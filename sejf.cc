#include <algorithm>
#include <cstdlib>
#include "sejf.h"
#include <cstdint>
#include "kontroler.h"
#include <iostream>

Sejf::Sejf(std::string text, size_t available_accesses)
{
	this->text = text;
	this->available_accesses = available_accesses;
	this->controler = NULL;
}

void Sejf::operator=(Sejf& sejf)
{
	this->text = sejf.text;
	this->available_accesses = sejf.available_accesses;
	this->controler = sejf.controler;
}

int16_t Sejf::operator[](const size_t ind)
{
	if (ind >= text.size())
		return -1;

	if (this->available_accesses == 0)
	{
		this->kontroler().set_break_in();
		return -1;
	}
	int16_t result = text[ind];
	this->available_accesses--;
	return result;
}

void Sejf::operator+=(const size_t x)
{
	if (x >= 0)
		this->available_accesses += x;
}

void Sejf::operator*=(const size_t x)
{
	if (x > 0)
		this->available_accesses *= x;
}

void Sejf::operator-=(const size_t x)
{
	if (x >= 0)
		this->available_accesses -= x;
}

Kontroler Sejf::kontroler()
{
	if (this->controler == NULL) {
		Kontroler tmp = Kontroler();
		this->controler = &tmp;
	}
	return *(this->controler);
}

/*namespace std
{
	void swap(Sejf& s1, Sejf& s2)
	{
		swap(s1.controler, s2.controler);
		swap(s1.available_accesses, s2.available_accesses);
		swap(s1.text, s2.text);
	}
}*/
