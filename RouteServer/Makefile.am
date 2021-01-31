AUTOMAKE_OPTIONS=foreign
bin_PROGRAMS=route
route_SOURCES=main.cc \
			./proto/route.pb.cc \
			./proto/route.pb.h \
			./handler/handlerSession.h \
			./handler/handlerSession.cc \
			./handler/handler.h \
			./handler/handler.cc \
			../Common/network/serverApp.h \
			../Common/network/clientSession.h \
			../Common/network/clientSession.cc \
			../Common/network/conn.h 
INCLUDES=-I../Common/
DEFS+=-DDEBUG
