/*************************************************************************
    > File Name: clientSession.h
    > Author: zj.tian
    > Mail: t657645537@126.com 
    > Created Time: 2015年02月02日 星期一 15时52分45秒
 ************************************************************************/

#ifndef NETWORK_CLIENT_SESSION
#define NETWORK_CLIENT_SESSION

#include <iostream>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/bind.hpp>
using namespace std;
using boost::asio::ip::tcp;
#define max_len 1024

// data head struct
#pragma pack(1)
typedef struct __dataHead {
    /*******************/
    unsigned int _version;

    /*******************/
    unsigned char _reqID[2];
    unsigned char _reqType[2];
    /*******************/ 

    unsigned int _dataLen;
    
} dataHead;
#pragma pack()

class clientSession
	: public boost::enable_shared_from_this<clientSession>
{
	public:
		clientSession(boost::asio::io_service& ioservice)
			:m_socket(ioservice)
		{
		    cleanData();
		}
		~clientSession()
		{
			
		}

		tcp::socket& socket()
		{
			return m_socket;
		}

		void start();
	private:
		void cleanData()
		{
		    memset((void*)m_data,0,max_len);
		    memset((void*)m_head,0,sizeof(dataHead));
		}
		void handle_write(const boost::system::error_code& error);
		void handle_read_head(const boost::system::error_code& error,std::size_t len);
		void handle_read(const boost::system::error_code& error,std::size_t len);
	private:
		tcp::socket m_socket;
		char m_head[sizeof(dataHead)];
		char m_data[max_len];
};



#endif
