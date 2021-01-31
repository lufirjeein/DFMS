
#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
using boost::asio::ip::tcp;
using namespace std;
#define max_len 1024

// data head struct
#pragma pack(1)
typedef struct __dataHead {
    /*******************/
    unsigned int _version;

    /*******************/
    unsigned int _reqID;
    // < 255 char
    unsigned int _reqType;
    /*******************/ 

    unsigned int _dataLen;
    
} dataHead;
#pragma pack()


#pragma pack(1)
typedef struct _Message {
    // 0 - req
    // 1 - res
    // 2 - notify
    char chType;
    // 0 
    char chErrorCode;
    // head no
    // as: 1 - login
    char chMsgHeadNo;
    // HeadNo str
    char chMsgHead[36];
    unsigned int reqID;
    // msg body
    char* strMsgInfo;
}Message,*pMessage;
#pragma pack()


#endif
