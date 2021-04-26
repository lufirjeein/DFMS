/*************************************************************************
	> File Name: RouteServer/RouteServer.cc
	> Author: tianzuojian
	> Mail: t657645537@126.com 
	> Created Time: 2015年07月30日 星期四 15时43分58秒
 ************************************************************************/

#include <iostream>
#include "Common/PluginBase.hh"
using namespace std;

class RouteServer :
	public PluginBase
{
	public:
		RouteServer(int thePort):
			PluginBase(thePort,"RouteServer")
		{
				
		};
	virtual void start()
	{
		cout << "[RouteServer::start]" << endl;
		PluginBase::start();
	};
	virtual void stop()
	{
		PluginBase::stop();
	};
	virtual void networkCallback(const string& theStr)
	{
		PluginBase::networkCallback(theStr);
	};

};

extern "C" RouteServer* create(int thePort)
{
	return new RouteServer(thePort);
}
extern "C" void destroy(PluginBase* thePluginBase)
{
	delete thePluginBase;
}
