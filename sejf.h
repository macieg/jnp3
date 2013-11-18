#ifndef SEJF_H
#define SEJF_H
#include <iostream>
#include <string>
#include "kontroler.h"
#include <cstdint>
#include <utility>

/*
 * Klasa reprezentująca sejf.
 */
class Sejf final {

	friend class Kontroler;

	private:
		/**
		 * Informacja mówiąca, czy nastąpiło włamanie.
		 */
		bool break_in;

		/**
		 * Informacja mówiąca, czy ilość dostępów była zmanipulowana.
		 */
		bool is_manipulated;

		/**
		 * Ilość pozostałych dostępów do Sejfu.
		 */
		int available_accesses;

		/**
		 * Napis przechowywany w sejfie.
		 */
		std::string text;

		/**
		 * Obiekt kontrolera.
		 */
		Kontroler controler;

		/**
		 * Prywatny konstruktor uniemożliwiający skopiowanie sejfu.
		 */
		Sejf(const Sejf& sejf);

		/**
		 * Ustawia informację o próbie włamania.
		 */
		void set_break_in();

		/**
		 * Ustawia informację o próbie manipulacja.
		 */
		void set_is_manipulated();

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
		Kontroler kontroler();

		/**
		 * Operator przypisania dla rvalue.
		 */
		void operator=(Sejf&& sejf);

		/**
		 * Konstruktor kopiujący dla rvalue.
		 */
		Sejf(Sejf&& sejf);

		/**
		 * Zwraca informację o tym, czy nastąpiło włamanie.
		 */
		bool get_break_in() const;

		/**
		 * Zwraca informacje o tym, czy nasąpiła manipulacja.
		 */
		bool get_is_manipulated() const;

		/**
		 * Zwraca liczbę dostępów do sejfu.
		 */
		int get_available_accesses() const;

};

#endif
