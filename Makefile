CFLAGS=-O2 -Wall -std=c++11

all: kontroler.o sejf.o

kontroler.o: sejf.h kontroler.h kontroler.cc
	g++ $(CFLAGS) -c kontroler.cc -o kontroler.o

sejf.o: kontroler.o sejf.h sejf.cc
	g++ $(CFLAGS) -c sejf.cc -o 

#Do testowania
test: test.cc sejf.o
	g++ $(CFLAGS) -O2 -Wall sejf.o test.cc -o test

clean:
	rm *.o
