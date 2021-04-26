/*************************************************************************
    > File Name: ../PluginManager/PluginBase.hh
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2015年07月19日 星期日 20时54分22秒
 ************************************************************************/

#include <string>
#include <glog/logging.h>
using namespace std;

class PluginBaseCallback {
	virtual void send(const string& thePluginName,const string& theStr ) = 0;
};

class PluginBase {
	public:
		PluginBase(const int& thePort,const string& thePluginName)
		{
			// google::InitGoogleLogging(thePluginName.c_str());
		};
		virtual ~PluginBase()
		{
			LOG(INFO) << "[PluginBase::~PluginBase]";
		};

		virtual void start()
		{
			// ::system("echo PluginBase > PluginTemplteTestFile");
			// cout << "[PluginBase::start]" << endl;
			LOG(INFO) << "[PluginBase::start]";
		};
		virtual void stop()
		{
			LOG(INFO) << "[PluginBase::stop]";
		};
		virtual void networkCallback(const string& theStr)
		{
			LOG(INFO) << "[PluginBase::networkCallback] theStr=" << theStr;
		};
	private:
		PluginBaseCallback*	myPluginBaseCallback;
};

