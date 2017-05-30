all: a.out test

a.out: merge_sort.cpp
	g++ -std=c++11 -Wall -g3  -D_GLIBCXX_DEBUG $< -o a.out

test:
	./a.out
