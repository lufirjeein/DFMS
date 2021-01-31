#include "clientSession.h"
#include <xlib/constants.h>
#include <xlib/log.h>
#include <xlib/memory.h>
#include <string.h>
US_XLIB_NS

void clientSession::start()
{
    boost::asio::async_write(m_socket,
			     boost::asio::buffer("link successed!"),
			     boost::bind(&clientSession::handle_write,shared_from_this(),
					 boost::asio::placeholders::error));

    m_socket.async_read_some(boost::asio::buffer(m_head,sizeof(dataHead)),
			     boost::bind(&clientSession::handle_read_head,shared_from_this(),
					 boost::asio::placeholders::error,
					 boost::asio::placeholders::bytes_transferred));
}

void clientSession::handle_write(const boost::system::error_code& error)
{
    if (error) {
	DEBUG_INFO("[clientSession::handle_write] error.message = " << error.message());
	m_socket.close();
    }
}

void clientSession::handle_read_head(const boost::system::error_code& error,std::size_t len)
{
    static int __allRecevieHeadLen = 0;
    __allRecevieHeadLen += len;

    do {
	if (!error) {
	    if (__allRecevieHeadLen < sizeof(dataHead)) {
		DEBUG_INFO("[clientSession::handle_read_head] (len+strlen(m_head)) < sizeof(dataHead);");
		DEBUG_INFO("[clientSession::handle_read_head] len = " << len);
		m_socket.async_read_some(boost::asio::buffer(m_head+__allRecevieHeadLen,
							     sizeof(dataHead)-__allRecevieHeadLen),
					 boost::bind(&clientSession::handle_read_head,shared_from_this(),
						     boost::asio::placeholders::error,
						     boost::asio::placeholders::bytes_transferred));
	    } else if (__allRecevieHeadLen == sizeof(dataHead)) {
		DEBUG_INFO("[clientSession::handle_read_head] (len+strlen(m_head)) == sizeof(dataHead);");
		dataHead __dataHead;
		memcpy(&__dataHead,m_head,sizeof(__dataHead));
		DEBUG_INFO("[clientSession::handle_read_head] __dataHead._version="<<__dataHead._version);
		DEBUG_INFO("[clientSession::handle_read_head] __dataHead._reqID="<<__dataHead._reqID);
		DEBUG_INFO("[clientSession::handle_read_head] __dataHead._reqType="<<__dataHead._reqType);
		DEBUG_INFO("[clientSession::handle_read_head] __dataHead.__dataLen="<<__dataHead._dataLen);
		__allRecevieHeadLen = 0;
		memset(m_data,0,max_len);
		m_socket.async_read_some(boost::asio::buffer(m_data,max_len),
					 boost::bind(&clientSession::handle_read,shared_from_this(),
						     boost::asio::placeholders::error,
						     boost::asio::placeholders::bytes_transferred));
	    } else {
		DEBUG_INFO("[clientSession::handle_read_head] (len+strlen(m_head)) > sizeof(dataHead);");
		// write_log(E_LOG_INFO,"[client::handle_read_head] (len+strlen(m_head)) > sizeof(dataHead),the msg will throw away");
		__allRecevieHeadLen = 0;
		cleanData();
		m_socket.async_read_some(boost::asio::buffer(m_head,sizeof(dataHead)),
					 boost::bind(&clientSession::handle_read_head,shared_from_this(),
						     boost::asio::placeholders::error,
						     boost::asio::placeholders::bytes_transferred));
	    }
	} else {
	    DEBUG_INFO("[clientSession::handle_read_head] error.message = " << error.message());
	    // write_log(E_LOG_INFO,"[client::handle_read_head] error.message = " << error.message());
	    __allRecevieHeadLen = 0;
	    cleanData();
	    m_socket.close();
	}	
    } while(0);
}

void clientSession::handle_read(const boost::system::error_code& error,std::size_t len)
{
    DEBUG_INFO("[clientSession::handle_read] begin");
    static int __allRecevieDataLen = 0;
    __allRecevieDataLen += len;

    do {
	dataHead __dataHead;
	memcpy(&__dataHead,m_head,sizeof(__dataHead));

	if (!error) {
	    if (__allRecevieDataLen < __dataHead._dataLen) {
		DEBUG_INFO("[clientSession::handle_read] (len+strlen(m_data)) < __dataHead._dataLen;");
		DEBUG_INFO("[clientSession::handle_read] len = " << len);
		m_socket.async_read_some(boost::asio::buffer(m_data+__allRecevieDataLen,
							     __dataHead._dataLen-__allRecevieDataLen),
					 boost::bind(&clientSession::handle_read,shared_from_this(),
						     boost::asio::placeholders::error,
						     boost::asio::placeholders::bytes_transferred));
	    } else if (__allRecevieDataLen == __dataHead._dataLen) {
		DEBUG_INFO("[clientSession::handle_read] (len+strlen(m_data)) == __dataHead._dataLen;");
		__allRecevieDataLen = 0;
		recevied();
		m_socket.async_read_some(boost::asio::buffer(m_head,sizeof(dataHead)),
					 boost::bind(&clientSession::handle_read_head,shared_from_this(),
						     boost::asio::placeholders::error,
						     boost::asio::placeholders::bytes_transferred));
	    } else {
		DEBUG_INFO("[clientSession::handle_read] (len+strlen(m_data)) > __dataHead._dataLen;");
		// write_log(E_LOG_INFO,"[client::handle_read] (len+strlen(m_data)) > __dataHead._dataLen,the msg will throw away");
		__allRecevieDataLen = 0;
		cleanData();
		m_socket.async_read_some(boost::asio::buffer(m_head,sizeof(dataHead)),
					 boost::bind(&clientSession::handle_read_head,shared_from_this(),
						     boost::asio::placeholders::error,
						     boost::asio::placeholders::bytes_transferred));
	    }
	} else {
	    DEBUG_INFO("[clientSession::handle_read] error.message = " << error.message());
	    // write_log(E_LOG_INFO,"[client::handle_read] error.message = " << error.message());
	    __allRecevieDataLen = 0;
	    cleanData();
	    m_socket.close();
	}	
    } while(0);
    DEBUG_INFO("[clientSession::handle_read] end");
}

void clientSession::recevied()
{
    DEBUG_INFO("[clientSession::recevied] start");
 
    dataHead __dataHead;
    memcpy(&__dataHead,m_head,sizeof(__dataHead));

    Message* __pMsg = (Message*)xlib_alloc(sizeof(Message));
    assert(__pMsg);
    memset(__pMsg,0,sizeof(Message));    
    __pMsg->chType = 0;
    __pMsg->chErrorCode = 0;
    __pMsg->chMsgHeadNo = __dataHead._reqType;
    __pMsg->reqID = __dataHead._reqID;
    __pMsg->strMsgInfo = (char*)(xlib_alloc(__dataHead._dataLen+1));
    memset(__pMsg->strMsgInfo,0,__dataHead._dataLen+1);
    memcpy(__pMsg->strMsgInfo,m_data,__dataHead._dataLen);
    // __pMsg->strMsgInfo.append(m_data,strlen(m_data));

    if (NULL == m_pQueue) {
	DEBUG_INFO("[clientSession::recevied] NULL == m_pQueue");
	// write_log(E_LOG_ERROR,"[clientSession] m_pQueue == NULL");
    } else {
	DEBUG_INFO("[clientSession::recevied] queue_add_data");
	queue_add_data(m_pQueue,__pMsg,sizeof(*__pMsg));
    }

    xlib_free(__pMsg);
    cleanData();
    DEBUG_INFO("[clientSession::recevied] end");
}
