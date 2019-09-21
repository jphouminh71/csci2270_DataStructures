# Makefile for CSCI 2270 lab 6
# Date: 10/8/18

# USAGE:
# - to make all targets:
#      > make
# - to make just QueueLL:
#      > make queue
# - to make just StackLL:
#      > make stack
# - to clean:
#      > make clean

CC=g++
CFLAGS=-std=c++11 -Wall
TARGETS = queue stack

all:
	@make $(TARGETS)

queue: QueueLL.cpp DriverQueue.cpp
	$(CC) -o $@ $(CFLAGS) $^

stack: StackLL.cpp DriverStack.cpp
	$(CC) -o $@ $(CFLAGS) $^

clean:
	rm $(TARGETS)
