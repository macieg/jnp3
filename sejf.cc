#include <algorithm>
#include <cstdlib>
#include "sejf.h"
#include <cstdint>
#include "kontroler.h"
#include <iostream>
#include <utility>
#include <stdexcept>

Sejf::Sejf(std::string text, int available_accesses)
{
	if (available_accesses < 0)
		throw std::invalid_argument(std::string("Liczba dostepow"\
					"do sejfu nie moze byc ujemna."));
	this->text = text;
	this->controler = new Kontroler(available_accesses);
}

Sejf::~Sejf()
{
	delete this->controler;
}

void Sejf::operator=(Sejf& sejf)
{
	this->text = sejf.text;
	this->kontroler().available_accesses =
					sejf.kontroler().available_accesses;
	this->controler = sejf.controler;
}

int16_t Sejf::operator[](const size_t ind)
{
	if (ind >= text.size())
		return -1;

	if (this->kontroler().available_accesses == 0)
	{
		this->kontroler().set_break_in();
		return -1;
	}
	int16_t result = text[ind];
	this->kontroler().available_accesses--;
	return result;
}

void Sejf::operator+=(const int x)
{
	if (x >= 0)
	{
		this->kontroler().available_accesses += x;
		this->kontroler().set_is_manipulated();
	}
}

void Sejf::operator*=(const int x)
{
	if (x > 0)
	{
		this->kontroler().available_accesses *= x;
		this->kontroler().set_is_manipulated();
	}
}

void Sejf::operator-=(const int x)
{
	if ((x >= 0) && (x <= this->kontroler().available_accesses))
	{
		this->kontroler().available_accesses -= x;
		this->kontroler().set_is_manipulated();

	}
}

Kontroler& Sejf::kontroler()
{
	return *(this->controler);
}

