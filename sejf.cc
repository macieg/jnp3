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
	this->break_in = false;
	this->is_manipulated = false;
	this->available_accesses = available_accesses;
	this->text = text;
}

void Sejf::set_break_in()
{
	this->break_in = true;
}

void Sejf::set_is_manipulated()
{
	this->is_manipulated = true;
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

void Sejf::operator=(Sejf& sejf)
{
	this->text = sejf.text;
	this->available_accesses = available_accesses;
	this->controler = sejf.controler;
}

int16_t Sejf::operator[](const size_t ind)
{
	if (ind >= text.size())
		return -1;

	if (this->available_accesses == 0)
	{
		this->set_break_in();
		return -1;
	}
	int16_t result = text[ind];
	this->available_accesses--;
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
		this->available_accesses *= x;
		this->set_is_manipulated();
	}
}

void Sejf::operator-=(const int x)
{
	if ((x >= 0) && (x <= this->available_accesses))
	{
		this->available_accesses -= x;
		this->set_is_manipulated();

	}
}

Sejf::Sejf(Sejf&& sejf) :
	controler(this)
{
	this->break_in = sejf.get_break_in();
	this->is_manipulated = sejf.get_is_manipulated();
	this->available_accesses = sejf.get_available_accesses();
}

void Sejf::operator=(Sejf&& sejf)
{
	this->break_in = sejf.get_break_in();
	this->is_manipulated = sejf.get_is_manipulated();
	this->available_accesses = sejf.get_available_accesses();
}

Kontroler Sejf::kontroler()
{
	return controler;
}

