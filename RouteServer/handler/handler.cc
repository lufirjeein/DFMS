#include "handler.h"
#include "handlerSession.h"
#include <xlib/list.h>
#include <xlib/constants.h>
#include <xlib/queue.h>
#include <xlib/net.h>
#include <xlib/log.h>
#include <xlib/pthreadPool.h>
#include <assert.h>
#include "network/serverApp.h"
#include <boost/thread.hpp>
#include <boost/foreach.hpp>
#include <stdlib.h>
#include <signal.h>
US_XLIB_NS;

static boost::asio::io_service ioService;
static bool isRun = false;
const static int listenPort = 8888;
const static int sessionNumber = 16;
static x_queue* requestDataQueue = NULL; 
static int sign[6] = 
{
    SIGABRT,SIGFPE,SIGILL,SIGINT,SIGSEGV,SIGTERM
};

void sign_handler(int _sign)
{
    write_log(E_LOG_INFO,"[sign_handler]");
    isRun = false;
    // sem_post(requestDataQueue->notify_add_sem);
    // sem_post(requestDataQueue->notify_add_sem);
    sem_post(requestDataQueue->notify_add_sem);
    ioService.stop();
}

void read(int fd, char* buf,int len)
{
    if (NULL == requestDataQueue) {
	write_log(E_LOG_ERROR,"requestDataQueue is NULL");
	return ;
    }

    if (NULL == queue_add_data(requestDataQueue,buf,strlen(buf))) {
	write_log(E_LOG_INFO,"queue_add_data fail");
	return ;
    }
}

void read_head(int fd, char* buf,int len)
{
    read_buf(fd,100,read);
}

void accept(int fd)
{
    read_buf(fd,1,read_head);
}

static void __run(x_list* _list)
{
    boost::thread __ioServiceThread(boost::bind(&boost::asio::io_service::run,&ioService));

    int __i = 0;
    while (isRun) {
	__i=(++__i)%sessionNumber;
	sem_wait(requestDataQueue->notify_add_sem);

	if (!isRun) break ;

	x_list* __pList = get_index_list(_list,__i);
	assert(__pList);

	handlerSession* __pHandlerSession = (handlerSession*)__pList->data;
	assert(__pHandlerSession);

	// _pHandlerSession->

    }
    __ioServiceThread.join();

    // remove handlerSession
    for (__i = 0;__i < sessionNumber;++__i) {
	x_list* __listNode = get_index_list(_list,__i);
	assert(__listNode);
	xlib_free(__listNode->data);
    }
    delete_all_list(_list);
}

static void _run()
{
    BOOST_FOREACH(int _sign,sign)
    {
	signal(_sign,sign_handler);
    }

    // init request queue
    x_queue_config __config;
    __config.x_read_mode = E_QueueReadTail;
    strcpy(__config.name,"requestDataQueue");
    requestDataQueue = create_queue(&__config);
    assert(requestDataQueue);

    // init socket
    using boost::asio::ip::tcp;
    tcp::endpoint __endPoint(tcp::v4(),listenPort);
    serverApp __sa(ioService,__endPoint);

    // set runing
    isRun = true;

    x_list* __list = get_singleton_list();
    assert(__list);
    if (NULL != __list) {
	int __i;
	for (__i=0;__i<sessionNumber;++__i) {
	    handlerSession* __pHs = new handlerSession();
	    assert(__pHs);
	    add_node_end(__list,__pHs);
	}
	return __run(__list);	
    }
}

void run()
{
    return _run();
}
