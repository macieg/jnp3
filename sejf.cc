#include <algorithm>
#include <cstdlib>
#include "sejf.h"

Sejf::Sejf(std::string text, size_t available_accesses)
{
	this->text = text;
	this->available_accesses = available_accesses;
	this->controler = NULL;
}

short int Sejf::operator[](const size_t ind)
{
	if (ind >= text.size())
		return -1;

	if (this->available_accesses == 0)
	{
		this->kontroler();
		return -1;
	}

	this->available_accesses--;
	return text[ind];
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
	if (this->controler == NULL)
		this->controler = Kontroler();
	return this->controler;
}
