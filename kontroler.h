#ifndef KONTROLER_H
#define KONTROLER_H
#include <iostream>

class Sejf;

/*
 * Klasa kontrolera.
 */
class Kontroler final {

	friend std::ostream& operator<<(std::ostream &out,
						const Kontroler &kontroler);

	friend class Sejf;

	private:

		const Sejf* sejf;

		/**
		 * Prywatny konstruktor kontrolera "zaprzyjaźniony" z sejfem.
		 */
		Kontroler(const Sejf *sejf);

	public:

		/**
		 * Operator bool.
		 */
		 operator bool() const;

		 /**
		  * Zwraca informację o tym, czy nastąpiło włamanie.
		  */
		 bool break_in() const;

		 /**
		  * Zwraca informacje o tym, czy nasąpiła manipulacja.
		  */
		 bool is_manipulated() const;
};

#endif
