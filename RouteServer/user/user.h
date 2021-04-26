
#ifndef _USER_H_
#define _USER_H_

typedef struct _LoginUser {
	std::string username;
	std::string password;
	std::string macAddress;
	std::string socketMD5;
} LoginUser;

class user 
{
	public:
		user();
};

#endif
