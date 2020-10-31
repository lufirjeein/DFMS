/*************************************************************************
    > File Name: serverApp.h
    > Author: zj.tian
    > Mail: t657645537@126.com 
    > Created Time: 2015年02月02日 星期一 17时51分44秒
 ************************************************************************/
#ifndef NETWORK_SERVERAPP
#define NETWORK_SERVERAPP

#include "clientSession.h"
#include <iostream>
#include <xlib/log.h>
using namespace std;
US_XLIB_NS;

class serverApp
{
    typedef boost::shared_ptr<clientSession> session_ptr;
 public:
    serverApp(boost::asio::io_service& ioservice,tcp::endpoint& endpoint)
	:m_ioservice(ioservice),
	m_acceptor(ioservice,endpoint)
	{
	    session_ptr new_session(new clientSession(ioservice));
	    m_acceptor.async_accept(new_session->socket(),
				    boost::bind(&serverApp::handle_accept,this,
						boost::asio::placeholders::error,
						new_session));
	}
    ~serverApp()
    {
    }

 private:
    void handle_accept(const boost::system::error_code& error,session_ptr& session)
    {
		if (!error) {
			write_log(E_LOG_INFO,"[serverApp::handle_accept]");
			session->start();
			session_ptr new_session(new clientSession(m_ioservice));
			m_acceptor.async_accept(new_session->socket(),
					boost::bind(&serverApp::handle_accept,this,
						boost::asio::placeholders::error,
						new_session));
		}
	}

 private:
    boost::asio::io_service& m_ioservice;
    tcp::acceptor m_acceptor;
};

#endif

