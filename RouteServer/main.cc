/*************************************************************************
    > File Name: main.cpp
    > Author: zj.tian
    > Mail: t657645537@126.com 
    > Created Time: 2015年01月08日 星期四 16时43分35秒
 ************************************************************************/

#include <iostream>
#include <xlib/log.h>
#include <xlib/constants.h>
#include <xlib/pthreadPool.h>
#include <unistd.h>
#include "proto/route.pb.h"
#include "handler/handler.h"
#include <google/protobuf/message.h>
#define _SHARED_PTR_H
#include <google/protobuf/text_format.h>
#undef _SHARED_PTR_H
#include <string>
#include "network/serverApp.h"
using namespace std;
using namespace google::protobuf;
using namespace DFMS::ROUTE;
US_XLIB_NS;

int main(int argc,const char* argv[])
{
	create_thread_pool();
	init_log(true);
	write_log(E_LOG_INFO,"RouteServer starting");
	  
 	run();

	sleep(2);
	destroy_log();
	destroy_thread_pool();

  return 0;
}
