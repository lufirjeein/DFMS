/*************************************************************************
    > File Name: main.cpp
    > Author: zj.tian
    > Mail: t657645537@126.com 
    > Created Time: 2015年01月08日 星期四 16时43分35秒
 ************************************************************************/

#include <iostream>
#include <xlib/constants.h>
#include <unistd.h>
#include "proto/route.pb.h"
#include "handler/handler.h"
#include <google/protobuf/message.h>
#define _SHARED_PTR_H
#include <google/protobuf/text_format.h>
#undef _SHARED_PTR_H
#include <string>
#include <glog/logging.h>
#include "network/serverApp.h"
#include "network/conn.h"
using namespace std;
using namespace google::protobuf;
using namespace DFMS::ROUTE;
US_XLIB_NS;

int main(int argc,const char* argv[])
{
	google::InitGoogleLogging(argv[0]);
//    int ret = create_thread_pool();
//    assert(ret == 0);
//    ret = init_log(true);
//    assert(ret == 0);
//    write_log(E_LOG_INFO,"RouteServer starting");
	  
    run();
   
//    sleep(2);
//    destroy_log();
//    destroy_thread_pool();

    return 0;
}
