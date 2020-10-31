
#############################
CC=g++
TARGET=router
ARGU=-DRELEASED -fPIC -lpthread -levent -w -lxlib
XLIB_PATH=/home/rayoo/xLib/xLib/
ALL_INCULDE_PATHS=-I$(XLIB_PATH)
MKDIR=mkdir -p
OBJS_PATH=./obj/
############################


############################
F_:
	$(MKDIR) $(OBJS_PATH)
		make $(TARGET)
############################


############################
JSON_ALL_FILES=cJSON.cc cJSON.h
JSON_ALL_C_FILES=cJSON.cc
JSON_OBJ_FILE=$(OBJS_PATH)cJSON.o
############################
$(JSON_OBJ_FILE): $(JSON_ALL_FILES)
	$(CC) -c $(JSON_ALL_C_FILES) $(ALL_INCULDE_PATHS) $(ARGU) -o $(JSON_OBJ_FILE)

############################
LOG_ALL_FILES=log.cc log.h
LOG_ALL_C_FILES=log.cc
LOG_OBJ_FILE=$(OBJS_PATH)log.o
############################
$(LOG_OBJ_FILE): $(LOG_ALL_FILES)
	$(CC) -c $(LOG_ALL_C_FILES) $(ALL_INCULDE_PATHS) $(ARGU) -o $(LOG_OBJ_FILE)

############################
MEMORY_ALL_FILES=memory.cc memory.h
MEMORY_ALL_C_FILES=memory.cc
MEMORY_OBJ_FILE=$(OBJS_PATH)memory.o
############################
$(MEMORY_OBJ_FILE): $(MEMORY_ALL_FILES)
	$(CC) -c $(MEMORY_ALL_C_FILES) $(ALL_INCULDE_PATHS) $(ARGU) -o $(MEMORY_OBJ_FILE)

############################
NET_ALL_FILES=net.cc net.h
NET_ALL_C_FILES=net.cc
NET_OBJ_FILE=$(OBJS_PATH)net.o
############################
$(NET_OBJ_FILE): $(NET_ALL_FILES)
	$(CC) -c $(NET_ALL_C_FILES) $(ALL_INCULDE_PATHS) $(ARGU) -o $(NET_OBJ_FILE)

############################
QUEUE_ALL_FILES=queue.cc queue.h
QUEUE_ALL_C_FILES=queue.cc
QUEUE_OBJ_FILE=$(OBJS_PATH)queue.o
############################
$(QUEUE_OBJ_FILE): $(QUEUE_ALL_FILES)
	$(CC) -c $(QUEUE_ALL_C_FILES) $(ALL_INCULDE_PATHS) $(ARGU) -o $(QUEUE_OBJ_FILE)

############################
PTHREADPOOL_ALL_FILES=pthreadPool.cc pthreadPool.h
PTHREADPOOL_ALL_C_FILES=pthreadPool.cc
PTHREADPOOL_OBJ_FILE=$(OBJS_PATH)pthreadPool.o
############################
$(PTHREADPOOL_OBJ_FILE): $(PTHREADPOOL_ALL_FILES)
	$(CC) -c $(PTHREADPOOL_ALL_C_FILES) $(ALL_INCULDE_PATHS) $(ARGU) -o $(PTHREADPOOL_OBJ_FILE)

############################
MAIN_ALL_FILES=main.cc
MAIN_ALL_C_FILES=main.cc
MAIN_OBJ_FILE=$(OBJS_PATH)main.o
############################
$(MAIN_OBJ_FILE): $(MAIN_ALL_FILES)
	$(CC) -c $(MAIN_ALL_C_FILES) $(ALL_INCULDE_PATHS) $(ARGU) -o $(MAIN_OBJ_FILE)

############################
ALL_FILES=$(MAIN_FILES)
#ALL_OBJ_FILES=$(LOG_OBJ_FILE) $(JSON_OBJ_FILE) $(MEMORY_OBJ_FILE) $(NET_OBJ_FILE) $(QUEUE_OBJ_FILE) $(PTHREADPOOL_OBJ_FILE)
ALL_OBJ_FILES=$(MAIN_OBJ_FILE)
############################
$(TARGET):$(ALL_OBJ_FILES)
	$(CC) $(ARGU) -o $@ $(ALL_OBJ_FILES)
#$(TARGET):
#	$(CC) $(ARGU) -shared -o $@ *.h *.cc


.PHONY:clean all

clean:
	rm -rf $(ALL_OBJ_FILES) $(TARGET)

all:
	$(MKDIR) $(OBJS_PATH)
	make $(TARGET)
