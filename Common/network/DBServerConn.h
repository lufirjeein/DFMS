/*************************************************************************
  > File Name: DBServerConn.h
  > Author: zj.tian
  > Mail: t657645537@126.com 
  > Created Time: 2015年02月10日 星期二 16时47分53秒
 ************************************************************************/

#ifndef _DBSERVERCONN_H_
#define _DBSERVERCONN_H_

#include "conn.h"
#include <xlib/log.h>
#include <xlib/constants.h>
#include <iostream>
using namespace std;

class DBServerConn : public conn {
	public:
		DBServerConn(){};
		~DBServerConn(){};

		virtual void responseMsg(Message& _msg)
		{
			DEBUG_INFO("[DBServerConn::responseMsg]");
			DEBUG_INFO("[DBServerConn::responseMsg] end");
		};
};

static DBServerConn dbServerConn;
DBServerConn& getSingleDBServerConn()
{
	return dbServerConn;
};
DBServerConn* getSingleDBServerConn()
{
	return &dbServerConn;
};

#endif
