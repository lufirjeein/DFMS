#include "handler.h"
#include "handlerSession.h"
#include <xlib/list.h>
#include <xlib/constants.h>
#include <xlib/queue.h>
#include <xlib/net.h>
#include <xlib/log.h>
#include <assert.h>
US_XLIB_NS;

static bool isRun = false;
const int listenPort = 8888;
const int sessionNumber = 16;
static x_queue* requestDataQueue = NULL; 

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

static void __run(x_list* list)
{
	int i = 0;
	while (isRun) {
		i=(++i)%sessionNumber;
		sem_wait(requestDataQueue->notify_add_sem);

		if (!isRun) break ;

		x_list* _pList = get_index_list(list,i);
		assert(_pList);

		handlerSession* _pHandlerSession = (handlerSession*)_pList->data;
		assert(_pHandlerSession);

		// _pHandlerSession->

	}
}

static void _run()
{
	// init request queue
	x_queue_config _config;
	_config.x_read_mode = E_QueueReadTail;
	requestDataQueue = create_queue(&_config);
	assert(requestDataQueue);

	// init socket
	// listen_socket(create_socket(NULL,listenPort), accept);	

	x_list* _list = get_singleton_list();
	assert(_list);
	if (NULL != _list) {
		int _i;
		for (_i=0;_i<sessionNumber;++_i) {
			handlerSession* _pHs = new handlerSession();
			assert(_pHs);
			add_node_end(_list,_pHs);

			std::string str("abc");
			write_log(E_LOG_INFO,str.c_str());
		}
		return __run(_list);	
	}
}

void run()
{
	return _run();
}
