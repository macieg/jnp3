#include "sejf.h"
#include <string>
#include <iostream>
#include "kontroler.h"

int main()
{
	if (true)
	{
		//test dla destruktora
		Sejf sejf(std::string("hehe"), 10);
		std::cout << sejf.kontroler() << std::endl;
	}
	Sejf sejfik(std::string("hihi"));
	printf("%i, to byl sejfik[100]\n", sejfik[100]);
	Sejf s1("abc", 2);
	//bool sejf
	if (s1.kontroler()) {
		printf("fajnie\n");
	} else {
		printf("nie fajnie\n");
	}
	s1[2];
	//swap nie dziala.
	//std::swap(sejf, s1);
	std::cout << sejfik.kontroler() << " i zaraz bedziemy zmieniac"
		  << std::endl;
	sejfik+=2;
	std::cout << sejfik.kontroler() << std::endl;
	s1+=2;
	s1[1];
	s1[1];
	s1[1];
	s1[1];
	printf("%i, to byl sejf po wykonczonych probach\n", s1[1]);
	//bool sejf
	if (s1.kontroler()) {
		printf("nie fajnie\n");
	} else {
		printf("fajnie\n");
	}
	s1+=2;
	std::cout << s1.kontroler() << std::endl;
	printf("%i ojej\n", s1[2]);
	printf("a teraz to co wyzej %i\n", (int) 'c');
	Sejf k(std::string("Asdgg"), -5);
	printf("fajnie\n");
	//Sejf sejf2 = sejf;
	//Sejf sejf3(sejf);
}
