#include "sejf.h"

Sejf::Sejf(std::string text, size_t available_accesses)
{
	this->text = text;
	this->available_accesses = available_accesses;
}

void Sejf::swap(Sejf& sejf1, Sejf& sejf2)
{
	std::swap(sejf1.text, sejf2.text);
	std::swap(sejf1.available_accesses, sejf2.available_accesses);
}
