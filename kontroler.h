#ifndef KONTROLER_H
#define KONTROLER_H
#include <iostream>
#include "sejf.h"


/*
 * Klasa kontrolera.
 */
class Kontroler {

	friend class Sejf;
	private:

		/*
		 * Informacja mówiąca, czy nastąpiło włamanie.
		 */
		bool break_in;

		/*
		 * Informacja mówiąca, czy ilość dostępów była zmanipulowana.
		 */
		bool is_manipulated;

		/*
		 * Prywatny konstruktor kontrolera "zaprzyjaźniony" z sejfem.
		 */
		Kontroler();

	public:	

		/*
		 * Ustawia informację o próbie włamania.
		 */
		void set_break_in();

		/*
		 * Ustawia informację o próbie manipulacja.
		 */
		void set_is_manipulated();

		/*
		 * Operator do wypisywania informacji o próbach dostępu
		 * do sejfu.
		 */
		std::ostream& operator<<(std::ostream& out);
};

#endif
