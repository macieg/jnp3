CFLAGS=-O2 -Wall -std=c++11

all: kontroler.o sejf.o

kontroler.o: sejf.h kontroler.h kontroler.cc
	g++ $(CFLAGS) -c kontroler.cc -o kontroler.o

sejf.o: kontroler.o sejf.h sejf.cc
	g++ $(CFLAGS) -c sejf.cc -o sejf.o

#Do testowania
test: test.cc sejf.o kontroler.o
	g++ $(CFLAGS) -O2 -Wall kontroler.o sejf.o test.cc -o test

test0: test0.cc sejf.o kontroler.o
	g++ $(CFLAGS) -O2 -Wall kontroler.o sejf.o test0.cc -o test0

clean:
	rm *.o
