# Makefile
CXX_FLAG = --std=c++11 -g

prog1: prog1.o
	g++ $(CXX_FLAG) -o prog1 prog1.o

prog1.o: prog1.cpp
	g++ $(CXX_FLAG) prog1.cpp -c

clean:
	rm -f prog1 *.o