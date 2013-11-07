#include <algorithm>
#include <cstdlib>
#include "sejf.h"

Sejf::Sejf(std::string text, size_t available_accesses)
{
	this->text = text;
	this->available_accesses = available_accesses;
}

short int Sejf::operator[](const size_t ind)
{
	if (ind >= text.size() || this->available_accesses == 0)
		return -1;

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
