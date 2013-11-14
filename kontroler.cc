#include "kontroler.h"
#include <iostream>
Kontroler::Kontroler(int accesses)
{
	this->break_in = false;
	this->is_manipulated = false;
	this->available_accesses = accesses;
}

void Kontroler::set_break_in()
{
	this->break_in = true;
}

void Kontroler::set_is_manipulated()
{
	this->is_manipulated = true;
}

Kontroler::operator bool() const
{
	return (this->available_accesses > 0);
}


std::ostream& operator<<(std::ostream& out, const Kontroler &kontroler)
{
	if (kontroler.break_in)
	{
		out << "ALARM: WŁAMANIE!\n";
	}
	else if (kontroler.is_manipulated)
	{
		out << "ALARM: ZMANIPULOWANY!\n";
	}
	else
	{
		out << "OK" << std::endl;
	}
	return out;
}
