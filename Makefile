#############################################################   
# Makefile for shared library.  
# # 编译动态链接库  
# #############################################################  
# #set your own environment option  
CC = g++
CC_FLAG = -g -fPIC
#   
#   #set your inc and lib
INC = -I./include -I./src/ -I./util
LIB = -lpthread -lrt -lstdc++ -lm
  
#make target lib and relevant obj
PRG = libstorage.so
OBJ = src/free_file_table.o src/id_center.o src/index_file.o src/record_file.o src/storage_api.o \
src/store_client_center.o util/clock.o util/coding.o util/cond.o util/crc32c.o util/logger.o \
util/mutex.o util/thread.o util/timer.o

#all target
all:$(PRG)

$(PRG):$(OBJ)
	$(CC) -fPIC -shared -o $@ $(OBJ) $(LIB)

.SUFFIXES: .c .o .cc
%.o : %.cc
	$(CC) $(CC_FLAG) $(INC) -c $*.cc -o $*.o

.PRONY:clean
clean:
	@echo "Removing linked and compiled files......;"
	rm -f $(OBJ) $(PRG)