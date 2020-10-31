/*************************************************************************
    > File Name: handlerSession.h
    > Author: zj.tian
    > Mail: t657645537@126.com 
    > Created Time: 2015年01月09日 星期五 17时29分19秒
 ************************************************************************/

#include "../proto/route.pb.h"
#include <iostream>
using namespace std;

#ifndef _HANDLER_SESSION_H
#define _HANDLER_SESSION_H

class handlerSession {
	public:
		handlerSession();
		~handlerSession();
	
		int receiveMsg();
};

#endif
