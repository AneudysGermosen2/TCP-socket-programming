CXX = g++
CXXFLAGS = -g - Wall -std=c++17

all:	serv cliX cliY

serv:	server2.cpp
		g++ server2.cpp -o server

cliX:	clientX.cpp
		g++ clientX.cpp -o clientX

cliY: 	clientY.cpp
		g++ clientY.cpp -o clientY

.phony:		clean, run
clean:
			rm -f *- *o server clientX clientY
run:		./server
