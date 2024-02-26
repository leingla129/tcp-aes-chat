# 自动编译RSA算法的代码
NAME = rsa  #可执行文件名
.DEFAULT_GOAL = app  #默认目标为app
# Compilation flags
CC = g++  #编译器
LD = g++	#链接器
CFLAGS   += -O2 -Wall -Werror

OBJS = rsa.o main.o	#目标文件列表

main.o : 
	@$(CC) -c main.cpp	#编译
rsa.o : 
	@$(CC) -c rsa.cpp	#编译
app:$(OBJS)	#构建目标 "app" 的规则
	@echo + LD $@  #打印一条消息，表示正在链接（LD）生成 "app"
	@$(LD) $(OBJS) -o $(NAME) 

clean:
	@rm -rf $(OBJS) $(NAME)
