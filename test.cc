#include "sejf.h"
#include <string>
#include <iostream>
#include "kontroler.h"
using namespace std;
int main()
{
	Sejf sejf(std::string("hehe"), 10);
	Sejf sejfik(std::string("hihi"));
	Sejf s1("aaa", 2);
	s1[2];
	//s1 = sejf;
	printf("sukces! %i\n", s1[2]);
	auto k1 = s1.kontroler();
	cout << s1.kontroler();// << "test\n";
	//Sejf sejf2 = sejf;
	//Sejf sejf3(sejf);
}
