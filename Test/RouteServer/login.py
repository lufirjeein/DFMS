import struct
import route_pb2
from socket import *

class TcpClient:
    HOST='127.0.0.1'
    PORT=8888
    BUFSIZE=1024
    ADDR=(HOST,PORT)
    _user = route_pb2.userLoginRequest()
    _user.username='abc_username'
    _user.password='dfg_password'
    _user.macAddress='ert_macAddress'
    def __init__(self):
        self.client=socket(AF_INET,SOCK_STREAM)
        self.client.connect(self.ADDR)
	self.value = (1,1001,0,15)#len(self._user.SerializeToString()))
	self._struct = struct.Struct("IIII")
        self._dataHead = self._struct.pack(*self.value)
        self.client.send(self._dataHead)
        # self.client.send("testPythonLogin")
        # print("send to server : %s" %(self._dataHead))
        # self.client.send(self._user.SerializeToString())
        self.client.send("testPythonLogin")
        # print("send to server : %s" %(self._user.SerializeToString()))
        self.client.close()

if __name__=='__main__':
    client=TcpClient()
