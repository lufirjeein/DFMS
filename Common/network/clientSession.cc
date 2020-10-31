#include "clientSession.h"
#include <xlib/constants.h>
#include <xlib/log.h>
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
    do {
	if (!error) {
	    if ((len+strlen(m_head)) < sizeof(dataHead)) {
		DEBUG_INFO("[clientSession::handle_read_head] (len+strlen(m_head)) < sizeof(dataHead);");
		DEBUG_INFO("[clientSession::handle_read_head] len = " << len);
		DEBUG_INFO("[clientSession::handle_read_head] strlen(m_head) = " << strlen(m_head));
		m_socket.async_read_some(boost::asio::buffer(m_head+strlen(m_head)+len,
							     sizeof(dataHead)-strlen(m_head)-len),
					 boost::bind(&clientSession::handle_read_head,shared_from_this(),
						     boost::asio::placeholders::error,
						     boost::asio::placeholders::bytes_transferred));
	    } else if ((len+strlen(m_head)) == sizeof(dataHead)) {
		DEBUG_INFO("[clientSession::handle_read_head] (len+strlen(m_head)) == sizeof(dataHead);");
		memset(m_data,0,max_len);
		m_socket.async_read_some(boost::asio::buffer(m_data,max_len),
					 boost::bind(&clientSession::handle_read,shared_from_this(),
						     boost::asio::placeholders::error,
						     boost::asio::placeholders::bytes_transferred));
	    } else {
		DEBUG_INFO("[clientSession::handle_read_head] (len+strlen(m_head)) > sizeof(dataHead);");
		// write_log(E_LOG_INFO,"[client::handle_read_head] (len+strlen(m_head)) > sizeof(dataHead),the msg will throw away");
		cleanData();
		m_socket.async_read_some(boost::asio::buffer(m_head,sizeof(dataHead)),
					 boost::bind(&clientSession::handle_read_head,shared_from_this(),
						     boost::asio::placeholders::error,
						     boost::asio::placeholders::bytes_transferred));
	    }
	} else {
	    DEBUG_INFO("[clientSession::handle_read_head] error.message = " << error.message());
	    // write_log(E_LOG_INFO,"[client::handle_read_head] error.message = " << error.message());
	    m_socket.close();
	}	
    } while(0);
}

void clientSession::handle_read(const boost::system::error_code& error,std::size_t len)
{
    DEBUG_INFO("[clientSession::handle_read] begin");
    do {
	dataHead _dataHead;
	memcpy(&_dataHead,m_head,sizeof(_dataHead));

	if (!error) {
	    if ((len+strlen(m_data)) < _dataHead._dataLen) {
		DEBUG_INFO("[clientSession::handle_read] (len+strlen(m_data)) < _dataHead._dataLen;");
		DEBUG_INFO("[clientSession::handle_read] len = " << len);
		DEBUG_INFO("[clientSession::handle_read] strlen(m_data) = " << strlen(m_data));
		m_socket.async_read_some(boost::asio::buffer(m_data+strlen(m_data)+len,
							     _dataHead._dataLen-strlen(m_data)-len),
					 boost::bind(&clientSession::handle_read,shared_from_this(),
						     boost::asio::placeholders::error,
						     boost::asio::placeholders::bytes_transferred));
	    } else if ((len+strlen(m_data)) == _dataHead._dataLen) {
		DEBUG_INFO("[clientSession::handle_read] (len+strlen(m_data)) == _dataHead._dataLen;");
		cleanData();
		m_socket.async_read_some(boost::asio::buffer(m_head,sizeof(dataHead)),
					 boost::bind(&clientSession::handle_read_head,shared_from_this(),
						     boost::asio::placeholders::error,
						     boost::asio::placeholders::bytes_transferred));
	    } else {
		DEBUG_INFO("[clientSession::handle_read] (len+strlen(m_data)) > _dataHead._dataLen;");
		// write_log(E_LOG_INFO,"[client::handle_read] (len+strlen(m_data)) > _dataHead._dataLen,the msg will throw away");
		cleanData();
		m_socket.async_read_some(boost::asio::buffer(m_head,sizeof(dataHead)),
					 boost::bind(&clientSession::handle_read_head,shared_from_this(),
						     boost::asio::placeholders::error,
						     boost::asio::placeholders::bytes_transferred));
	    }
	} else {
	    DEBUG_INFO("[clientSession::handle_read] error.message = " << error.message());
	    // write_log(E_LOG_INFO,"[client::handle_read] error.message = " << error.message());
	    m_socket.close();
	}	
    } while(0);
    DEBUG_INFO("[clientSession::handle_read] end");
}
