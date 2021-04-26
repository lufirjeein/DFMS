#include "user.h"
#include <vector>
#include <map>
#include <string>
#include <boost/function.hpp>

#ifndef _USER_MANAGEMENT_H_
#define _USER_MANAGEMENT_H_


template <typename T>
class userManagement : protected std::map<std::string,T>
{
	typedef std::string ___Str;
	typedef std::map<___Str,T> ___Map;
	typedef ___Map::iterator	___MapIter;
	typedef std::pair<___Str,T> ___MapPair;

	typedef std::vector<T> ___Vec;
	typedef ___Vec::iterator ___VecIter;

	public:
		userManagement();
		explicit userManagement(int theNum);
		
		// get singleton
		static userManagement& getSingletonUserManagement(); 

		void login(LoginUser theLoginUser,
				boost::function<void (bool theLoginSuccess, T* theLoginUser)> theLoginCallback);	

		void logout(LoginUser theLoginUser);

		bool getUserBySocketMD5(___Str theSocketMD5, T&  theUser);
		bool getUserByUsername(___Str theUsername, T&  theUser);
		bool getUserByObjID(___Str theObjID, T&  theUser);
		bool searchUser(T& theSearchConditionUser, ___Vec&  theUserVec);

	private:
		// After a  certain strategy, the logout info will be delete.
		___Vec	m_vecLogoutUser;
};

#endif
