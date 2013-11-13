#include "kontroler.h"
#include <iostream>
Kontroler::Kontroler()
{
	this->break_in = false;
	this->is_manipulated = false;
}

void Kontroler::set_break_in()
{
	this->break_in = true;
}

void Kontroler::set_is_manipulated()
{
	this->is_manipulated = true;
}

std::ostream& operator<<(std::ostream& out, const Kontroler &kontroler)
{
	if (kontroler.break_in)
		out << kontroler.break_in << std::endl;
	else if (kontroler.is_manipulated)
		out << kontroler.is_manipulated << std::endl;
	else
		out << "OK" << std::endl;
	return out;
}
