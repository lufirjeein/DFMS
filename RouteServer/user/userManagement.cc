#include "userManagement.h"
#include <boost/foreach.hpp>

template<typename T>
userManagement::userManagement()
{
}

template<typename T>
userManagement::userManagement(int theNum)
{
	
}

template<typename T>
userManagement& userManagement::getSingletonUserManagement()
{
	// multi-thread ?
	static userManagement aUserManagement;
	return aUserManagement;
}

template<typename T>
void userManagement::login(LoginUser theLoginUser,
		boost::function<void (bool theLoginSuccess, T* theLoginUser)> theLoginCallback)
{
	user _user;
	memset(&_user,0,sizeof(_user));
	_user.setLoginUser(theLoginUser);
	
	{
		___MapIter _userIter = std::find(begin(),end(),_user);
		if (end() != _userIter) {
			// already login
			theLoginCallback(false,NULL);
			return ;
		}
	}
	{
		__VecIter _userIter = 
			std::find(m_vecLogoutUser.begin(),m_vecLogoutUser.end(),_user);
		if (m_vecLogoutUser.end() != _userIter) {
			// already logout
			// (*_userIter).login(theLoginUser);
			// (*_userIter).login(theLoginUser.username,theLoginUser.password);
			if ((*_userIter).login(_user)) {
				insert(___MapPair(theLoginUser.socketMD5,(T)(*_userIter)));
				m_vecLogoutUser.earse(_userIter);
				theLoginCallback(true,(T*)_userIter);
			} else {
				theLoginCallback(false,NULL);
				// send event
			}
			return ;
		}
	}
}

template<typename T>
void userManagement::logout(LoginUser theLoginUser)
{

}

template<typename T>
bool userManagement::getUserBySocketMD5(___Str theSocketMD5, T&  theUser)
{
	___MapIter __mapIter = ___Map::find(theSocketMD5);
	if (__mapIter != ___Map::end()) {
		theUser = __mapIter->second;
		return true;
	}
	return false;
}
template<typename T>
bool userManagement::getUserByUsername(___Str theUsername, T&  theUser)
{
	typedef typename const  ___Map::value_type ___ConstPair;
	BOOST_FOREACH(___ConstPair& _thePair,this)
	{
		T __user = _thePair.second; 	
		if (__user.getUsername() == theUsername) {
			theUser = __user;
			return true;
		}
	}
	return false;
}
template<typename T>
bool userManagement::getUserByObjID(___Str theObjID, T&  theUser)
{
	return false;
}
template<typename T>
bool userManagement::searchUser(T& theSearchConditionUser, ___Vec&  theUserVec)
{
	return false;
}
