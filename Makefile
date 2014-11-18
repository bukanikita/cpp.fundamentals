CC=gcc
CXX=g++
RM=rm -f
STD=-std=c++0x

BINARY=18_task_1_main 18_task_3_main

all: $(BINARY)

18_task_1_main: 
	$(CXX) $(DBG) 18_task_1_main.cpp $(STD) -o 18_task_1_main

18_task_3_main: 
	$(CXX) $(DBG) 18_task_3_main.cpp $(STD) -o 18_task_3_main

clean: 
	$(RM) $(BINARY)