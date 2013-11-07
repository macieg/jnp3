CFLAGS=-O2 -Wall -std=c++11

all: sejf.o

sejf.o: sejf.h sejf.cc
	g++ $(CFLAGS) -c sejf.cc -o sejf.o

#Do testowania
test: test.cc sejf.o
	g++ $(CFLAGS) -O2 -Wall -std=c++11 sejf.o test.cc -o test

clean:
	rm *.o
