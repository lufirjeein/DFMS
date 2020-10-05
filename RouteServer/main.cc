/*************************************************************************
    > File Name: main.cpp
    > Author: zj.tian
    > Mail: t657645537@126.com 
    > Created Time: 2015年01月08日 星期四 16时43分35秒
 ************************************************************************/

#include <iostream>
#include <log.h>
#include <constants.h>
#include <pthreadPool.h>
#include <unistd.h>
using namespace std;
US_XLIB_NS;

int main(int argc,const char* argv[])
{
  create_thread_pool();
  init_log(true);
  write_log(E_LOG_INFO,"RouteServer starting");
  sleep(2);
  destroy_log();
  destroy_thread_pool();
  return 0;
}
