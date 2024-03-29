# 自动编译DES算法的代码
NAME = server
.DEFAULT_GOAL = all
# Compilation flags
CC = g++
LD = g++
CFLAGS   += -O2 -Wall -Werror

OBJS_S = aes.o gmult.o  rsa.o tcp-server.o 
OBJS_C = aes.o gmult.o  rsa.o tcp-client.o 

aes.o : 
	@$(CC) -c aes-src/aes.cpp
gmult.o:
	@$(CC) -c aes-src/gmult.cpp
rsa.o :
	@$(CC) -c rsa-src/rsa.cpp
tcp-client.o : 
	@$(CC) -c tcp-client.cpp
tcp-server.o : 
	@$(CC) -c tcp-server.cpp



all: server client

server:$(OBJS_S)
	@echo + LD $@
	@$(LD) $(OBJS_S) -o server

client:$(OBJS_C)
	@echo + LD $@
	@$(LD) $(OBJS_C) -o client

clean:
	@rm -rf $(OBJS_S) $(OBJS_C) server client