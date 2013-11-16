#include "kontroler.h"
#include <iostream>

Kontroler::Kontroler(Sejf* sejf)
{
	this->sejf = sejf;
}

Kontroler::operator bool() const
{
	return false;
	//return (this->sejf->_available_accesses() > 0);
}

bool Kontroler::break_in() const
{
	return (sejf->get_break_in());
}

bool Kontroler::is_manipulated() const
{
	return (sejf->get_is_manipulated());
}

std::ostream& operator<<(std::ostream& out, const Kontroler &kontroler)
{
	if (kontroler.break_in())
	{
		out << "ALARM: WŁAMANIE!\n";
	}
	else if (kontroler.is_manipulated())
	{
		out << "ALARM: ZMANIPULOWANY!\n";
	}
	else
	{
		out << "OK" << std::endl;
	}
	return out;
}
