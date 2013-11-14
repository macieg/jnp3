#ifndef SEJF_H
#define SEJF_H
#include <iostream>
#include <string>
#include "kontroler.h"
#include <cstdint>
#include <utility>

class Kontroler;
/*
 * Klasa reprezentująca sejf.
 */

class Sejf final {

	private:

		/**
		 * Napis przechowywany w sejfie.
		 */
		std::string text;

		/**
		 * Obiekt kontrolera.
		 */
		Kontroler* controler;

		/**
		 * Prywatny konstruktor uniemożliwiający skopiowanie sejfu.
		 */
		Sejf(const Sejf& sejf);

		/**
		 * Prywatne przeciążenie operatorów, aby uniemożliwić
		 * modyfikację.
		 */
		void operator=(Sejf& sejf);
		void operator<<=(const Sejf& sejf);
		void operator>>=(const Sejf& sejf);
		void operator&=(const Sejf& sejf);
		void operator^=(const Sejf& sejf);
		void operator|=(const Sejf& sejf);
		void operator%=(const Sejf& sejf);
	public:

		/**
		 * Konstruktor przyjmujący jako argument napis, który będzie
		 * przechowywany w sejfie, oraz być może liczbę możliwych
		 * dostępów do sejfu.
		 */
		Sejf(std::string text, int available_accesses = 42);

		/**
		 * Destruktor sejfu.
		 */
		~Sejf();

		/**
		 * Operator umożliwiający dostęp do litery napisu o indeksie
		 * przekazanym w argumencie.
		 */
		int16_t operator[](const size_t ind);

		/**
		 * Operator zwiększający ilość dostępów do sejfu o x.
		 */
		void operator+=(const int x);

		/**
		 * Operator zwiększający ilość dostępów do sejfu x razy.
		 */
		void operator*=(const int x);

		/**
		 * Operator zmniejszający ilość dostępów do sejfu o x.
		 */
		void operator-=(const int x);

		/**
		 * Podaje obiekt kontrolera.
		 */
		Kontroler& kontroler();
};

#endif
