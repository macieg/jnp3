#ifndef SEJF_H
#define SEJF_H
#include <string>
/*
 * Klasa reprezentująca sejf.
 */
class Sejf {

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
		 * Prywatny konstruktor uniemożliwiający skopiowanie sejfu.
		 */
		Sejf(const Sejf& sejf);

		/*
		 * Prywatne przeciążenie operacji przypisania uniemożliwiające przypisanie
		 * sejfowi innej wartości.
		 */
		void operator=(const Sejf sejf);
	public:

		/*
		 * Konstruktor przyjmujący jako argument napis, który będzie przechowywany w sejfie,
		 * oraz być może ilość możliwych dostępów do sejfu.
		 */
		Sejf(std::string text, size_t available_accesses = 42);

		/*
		 * Operator umożliwiający dostęp do litery napisu o indeksie przekazanym w argumencie.
		 */
		long long operator[](const size_t ind) const;
		
		/*
		 * Operator zwiększający ilość dostępów do sejfu o x.
		 */
		void operator+=(const size_t x) const;

		/*
		 * Operator zmniejszający ilość dostępów do sejfu o x.
		 */
		void operator-=(const size_t x) const;

		/*
		 * Operator zwiększający ilość dostępów do sejfu x razy.
		 */
		void operator*=(const size_t x) const;

		/*
		 * Przedefiniowanie funkcji swap.
		 */
		void swap(Sejf& sejf1, Sejf& sejf2);
};

#endif
