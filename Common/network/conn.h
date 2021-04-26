/*************************************************************************
  > File Name: conn.h
  > Author: zj.tian
  > Mail: t657645537@126.com 
  > Created Time: 2015年02月10日 星期二 16时48分50秒
 ************************************************************************/

#ifndef _CONN_H_
#define _CONN_H_

#include "__common.h"
#include <string>
#include <xlib/log.h>
#include <xlib/memory.h>
#include <xlib/constants.h>
US_XLIB_NS

class conn {
	public:
		conn(boost::asio::io_service& io_service,tcp::endpoint& endpoint)
			:m_socket(io_service)
		{
			cleanData();
		}
		~conn(){};

		virtual void sendMsg(const char* _msg,size_t len)
		{
			boost::asio::async_write(m_socket,boost::asio::buffer(_msg,len),
					boost::bind(&conn::handle_write,this,
						boost::asio::placeholders::error));

			m_socket.async_read_some(boost::asio::buffer(m_head,sizeof(dataHead)),
					boost::bind(&conn::handle_read_head,this,
						boost::asio::placeholders::error,
						boost::asio::placeholders::bytes_transferred));
		};
		virtual void responseMsg(Message& _msg) = 0;
	private:
		void cleanData()
		{
			memset((void*)m_data,0,max_len);
			memset((void*)m_head,0,sizeof(dataHead));
		}
		void handle_write(const boost::system::error_code& error)
		{
			if (error) {
				DEBUG_INFO("[conn::handle_write] error.message = " << error.message());
				write_log(E_LOG_INFO,"[conn::handle_write] error.message = %s",error.message().c_str());
				m_socket.close();
			}
		};
		void handle_read_head(const boost::system::error_code& error,size_t len)
		{
			static int __allRecevieHeadLen = 0;
			__allRecevieHeadLen += len;

			if (!error) {
				if (__allRecevieHeadLen < sizeof(dataHead)) {
					m_socket.async_read_some(boost::asio::buffer(m_head+__allRecevieHeadLen,
								sizeof(dataHead)-__allRecevieHeadLen),
							boost::bind(&conn::handle_read_head,this,
								boost::asio::placeholders::error,
								boost::asio::placeholders::bytes_transferred));
				} else if (__allRecevieHeadLen == sizeof(dataHead)) {
					__allRecevieHeadLen = 0;

					dataHead __dataHead;
					memcpy(&__dataHead,m_head,sizeof(__dataHead));
					memset(m_data,0,max_len);
					m_socket.async_read_some(boost::asio::buffer(m_data,max_len),
							boost::bind(&conn::handle_read,this,
								boost::asio::placeholders::error,
								boost::asio::placeholders::bytes_transferred));
				} else {
					__allRecevieHeadLen = 0;
					cleanData();
					m_socket.async_read_some(boost::asio::buffer(m_head,sizeof(dataHead)),
							boost::bind(&conn::handle_read_head,this,
								boost::asio::placeholders::error,
								boost::asio::placeholders::bytes_transferred));
				}
			} else {
				__allRecevieHeadLen = 0;
				cleanData();
				m_socket.close();
			}
		};

		void handle_read(const boost::system::error_code& error,size_t len)
		{
			static int __allRecevieDataLen = 0;
			__allRecevieDataLen += len;

			dataHead __dataHead;
			memcpy(&__dataHead,m_data,sizeof(__dataHead));

			if (!error) {
				if (__allRecevieDataLen < sizeof(dataHead)) {
					m_socket.async_read_some(boost::asio::buffer(m_data+__allRecevieDataLen,
								__dataHead._dataLen-__allRecevieDataLen),
							boost::bind(&conn::handle_read_head,this,
								boost::asio::placeholders::error,
								boost::asio::placeholders::bytes_transferred));
				} else if (__allRecevieDataLen == sizeof(dataHead)) {
					__allRecevieDataLen = 0;
					recevied();
					m_socket.async_read_some(boost::asio::buffer(m_head,sizeof(dataHead)),
							boost::bind(&conn::handle_read_head,this,
								boost::asio::placeholders::error,
								boost::asio::placeholders::bytes_transferred));
				} else {
					__allRecevieDataLen = 0;
					cleanData();
					m_socket.async_read_some(boost::asio::buffer(m_head,sizeof(dataHead)),
							boost::bind(&conn::handle_read_head,this,
								boost::asio::placeholders::error,
								boost::asio::placeholders::bytes_transferred));
				}
			} else {
				__allRecevieDataLen = 0;
				cleanData();
				m_socket.close();
			}
		};

		void recevied()
		{
			DEBUG_INFO("[conn::recevied] start");

			dataHead __dataHead;
			memcpy(&__dataHead,m_head,sizeof(__dataHead));

			Message* __pMsg = (Message*)xlib_alloc(sizeof(Message)+__dataHead._dataLen+1);
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

			// reponse msg
			responseMsg(*__pMsg);

			// free mem
			xlib_free(__pMsg->strMsgInfo);
			xlib_free(__pMsg);
			cleanData();
			DEBUG_INFO("[conn::recevied] end");
		}

	private:
		tcp::socket m_socket;
		char m_head[sizeof(dataHead)];
		char m_data[max_len];
};

#endif
