#include "handlerSession.h"
#include "defs/RouteDefs.h"
#include <xlib/memory.h>

handlerSession::handlerSession() 
{

}

handlerSession::~handlerSession()
{

}

int handlerSession::handleMsg(Message & _msg) 
{
	DEBUG_INFO("[handlerSession::handleMsg]");

	int __ret = 0;
	switch (_msg.chMsgHeadNo) {

		case RouteDefs::LoginMsgHeadNo:
			{
				DEBUG_INFO("[handlerSession::handleMsg] _msg.chMsgHeadNo=LoginMsgHeadNo.");
				DEBUG_INFO("[handlerSession::handleMsg] _msg.strMsgInfo="<<_msg.strMsgInfo);
				userLoginRequest __userLoginRequest;
				if (__userLoginRequest.ParseFromString(_msg.strMsgInfo)) {
					__ret = handleLogin(__userLoginRequest);

					dataHead _dataHead;
					memset(&_dataHead,0,sizeof(_dataHead));
					_dataHead._dataLen = strlen(_msg.strMsgInfo);

				} else {
					DEBUG_INFO("[handlerSession::handleMsg] ParseFromString return false");
					__ret = 1;
				}
			}
			break ;
	}
	DEBUG_INFO("[handlerSession::handleMsg] end");
	xlib_free(_msg.strMsgInfo);
	return __ret;
}

int handlerSession::handleLogin(userLoginRequest & _userLoginRequest)
{
	DEBUG_INFO("[handlerSession::handleLogin]");
	int __ret = 0;

	DEBUG_INFO("[handlerSession::handleLogin] _userLoginRequest.username()="<<_userLoginRequest.username());
	DEBUG_INFO("[handlerSession::handleLogin] _userLoginRequest.password()="<<_userLoginRequest.password());
	DEBUG_INFO("[handlerSession::handleLogin] _userLoginRequest.macaddress()="<<_userLoginRequest.macaddress());






	DEBUG_INFO("[handlerSession::handleLogin] end");
	return __ret;
}



