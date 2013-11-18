#include <algorithm>
#include <cstdlib>
#include "sejf.h"
#include <cstdint>
#include "kontroler.h"
#include <iostream>
#include <utility>
#include <stdexcept>

Sejf::Sejf(std::string text, int available_accesses) : 
	controler(this)
{
	if (available_accesses < 0)
		throw std::invalid_argument(std::string("Liczba dostepow"\
					"do sejfu nie moze byc ujemna."));
	break_in = false;
	is_manipulated = false;
	this->available_accesses = available_accesses;
	this->text = text;
}

void Sejf::set_break_in()
{
	break_in = true;
}

void Sejf::set_is_manipulated()
{
	is_manipulated = true;
}

bool Sejf::get_break_in() const
{
	return break_in;
}

bool Sejf::get_is_manipulated() const
{
	return is_manipulated;
}

int Sejf::get_available_accesses() const
{
	return available_accesses;
}

void Sejf::operator=(const Sejf& sejf)
{
	text = sejf.text;
	available_accesses = available_accesses;
	controler = sejf.controler;
}

int16_t Sejf::operator[](const size_t ind)
{
	if (ind >= text.size())
		return -1;

	if (this->available_accesses == 0)
	{
		set_break_in();
		return -1;
	}
	int16_t result = text[ind];
	available_accesses--;
	return result;
}

void Sejf::operator+=(const int x)
{
	if (x >= 0)
	{
		this->available_accesses += x;
		this->set_is_manipulated();
	}
}

void Sejf::operator*=(const int x)
{
	if (x > 0)
	{
		available_accesses *= x;
		set_is_manipulated();
	}
}

void Sejf::operator-=(const int x)
{
	if ((x >= 0) && (x <= this->available_accesses))
	{
		available_accesses -= x;
		set_is_manipulated();

	}
}

Sejf::Sejf(Sejf&& sejf) :
	controler(this)
{
	break_in = sejf.get_break_in();
	is_manipulated = sejf.get_is_manipulated();
	available_accesses = sejf.get_available_accesses();
}

void Sejf::operator=(Sejf&& sejf)
{
	break_in = sejf.get_break_in();
	is_manipulated = sejf.get_is_manipulated();
	available_accesses = sejf.get_available_accesses();
}

Kontroler Sejf::kontroler()
{
	return controler;
}

