#ifndef SEJF_H
#define SEJF_H
#include <iostream>
#include <string>
#include "kontroler.h"
#include <cstdint>

class Kontroler;
/*
 * Klasa reprezentująca sejf.
 */

class Sejf final {

	//friend void std::swap(Sejf& s1, Sejf& s2);

	private:

		/*
		 * Napis przechowywany w sejfie.
		 */
		std::string text;

		/*
		 * Ilość pozostałych dostępów do Sejfu.
		 */
		size_t available_accesses;

		/*
		 * Obiekt kontrolera.
		 */
		Kontroler* controler = NULL;

		/*
		 * Kopiuje dany sejf, zeby umożliwić zamianę dwóch sejfów.
		 */

		/*
		 * Prywatny konstruktor uniemożliwiający skopiowanie sejfu.
		 */
		Sejf(const Sejf& sejf);

		/*
		 * Prywatne przeciążenie operatorów, aby uniemożliwić modyfikację.
		 */
		void operator=(Sejf& sejf);
		void operator<<=(const Sejf& sejf);
		void operator>>=(const Sejf& sejf);
		void operator&=(const Sejf& sejf);
		void operator^=(const Sejf& sejf);
		void operator|=(const Sejf& sejf);
		void operator%=(const Sejf& sejf);
	public:

		/*
		 * Konstruktor przyjmujący jako argument napis, który będzie przechowywany w sejfie,
		 * oraz być może ilość możliwych dostępów do sejfu.
		 */
		Sejf(std::string text, size_t available_accesses = 42);

		/*
		 * Operator umożliwiający dostęp do litery napisu o indeksie przekazanym w argumencie.
		 */
		int16_t operator[](const size_t ind);

		/*
		 * Operator zwiększający ilość dostępów do sejfu o x.
		 */
		void operator+=(const size_t x);

		/*
		 * Operator zwiększający ilość dostępów do sejfu x razy.
		 */
		void operator*=(const size_t x);

		/*
		 * Operator zmniejszający ilość dostępów do sejfu o x.
		 */
		void operator-=(const size_t x);

		/*
		 * Zwraca obiekt kontrolera.
		 */
		Kontroler kontroler();
};

#endif
