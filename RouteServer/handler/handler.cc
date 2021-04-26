#include "handler.h"
#include "handlerSession.h"
#include <xlib/constants.h>
#include <assert.h>
#include "network/serverApp.h"
#include "network/port.h"
#include <boost/thread.hpp>
#include <boost/foreach.hpp>
#include <stdlib.h>
#include <signal.h>
#include <glog/logging.h>
#include <vector>
#include <queue>
// US_XLIB_NS;

boost::asio::io_service ioService;
static bool isRun = false;
const static int sessionNumber = 16;
std::queue<Message> requestDataQueue; 
boost::condition_variable requestDataCondition;
boost::mutex requestDataMutex;
boost::unique_lock<boost::shared_mutex> requestDataQueueLock; // queue lock
static int sign[6] = 
{
	SIGABRT,SIGFPE,SIGILL,SIGINT,SIGSEGV,SIGTERM
};

void sign_handler(int _sign)
{
	LOG(INFO) << "[sign_handler] _sing=" << _sign;
	if (isRun) {
		DEBUG_INFO("[sign_handler] _sign="<<_sign);
		isRun = false;
		requestDataCondition.notify_all();
		ioService.stop();
	}
}

void loopHandleWork(std::vector<handlerSession>& _handlerSessionVec)
{
	while (isRun) {
		boost::unique_lock<boost::mutex> lock(requestDataMutex);
		requestDataCondition.wait(lock);

		if (!isRun) break ;
		if (requestDataQueue.empty()) continue;

		requestDataQueueLock.lock();
		Message __msg = requestDataQueue.front();
		requestDataQueueLock.unlock();
			
		handlerSession __handlerSession = _handlerSessionVec[__msg.reqID%sessionNumber];
		__handlerSession.handleMsg(__msg);

		requestDataQueueLock.lock();
		requestDataQueue.pop();
		requestDataQueueLock.unlock();
	}
}

static void __run(std::vector<handlerSession>& _handlerSessionVec)
{
	boost::thread_group __threadGroup;
	__threadGroup.create_thread(boost::bind(&boost::asio::io_service::run,&ioService));
	__threadGroup.create_thread(boost::bind(&boost::asio::io_service::run,&ioService));
	__threadGroup.create_thread(boost::bind(&boost::asio::io_service::run,&ioService));
	__threadGroup.create_thread(boost::bind(&boost::asio::io_service::run,&ioService));
	__threadGroup.create_thread(boost::bind(&boost::asio::io_service::run,&ioService));
	__threadGroup.create_thread(boost::bind(&boost::asio::io_service::run,&ioService));
	__threadGroup.create_thread(boost::bind(&boost::asio::io_service::run,&ioService));
	__threadGroup.create_thread(boost::bind(&boost::asio::io_service::run,&ioService));
	ioService.post(boost::bind(&loopHandleWork,_handlerSessionVec));
	ioService.post(boost::bind(&loopHandleWork,_handlerSessionVec));
	ioService.post(boost::bind(&loopHandleWork,_handlerSessionVec));
	ioService.post(boost::bind(&loopHandleWork,_handlerSessionVec));

	__threadGroup.join_all();
}

static void _run()
{
	BOOST_FOREACH(int _sign,sign)
	{
		signal(_sign,sign_handler);
	}

	// init socket
	using boost::asio::ip::tcp;
	tcp::endpoint __endPoint(tcp::v4(),NETWORK_ALL_PORT::nRouteServerPort);
	serverApp __sa(ioService,__endPoint);

	// set runing
	isRun = true;

	std::vector<handlerSession> __handlerSessionVec(sessionNumber);
	return __run(__handlerSessionVec);	
}

void run()
{
	return _run();
}
