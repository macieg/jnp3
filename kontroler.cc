#include "kontroler.h"

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

std::ostream& Kontroler::operator<<(std::ostream& out)
{
	if (this->break_in)
		out << this->break_in << std::endl;
	else if (this->is_manipulated)
		out << this->is_manipulated << std::endl;
	else
		out << "OK" << std::endl;
	return out;
}
