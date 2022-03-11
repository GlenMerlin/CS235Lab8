all:
	g++ -g -std=c++11 -o test tests.cpp

test: all
	valgrind --leak-check=full ./test