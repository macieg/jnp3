/*
 * Klasa reprezentująca sejf.
 */
class Sejf {

	private:

		/*
		 * Napis przechowywany w sejfie.
		 */
		String text;

		/*
		 * Ilość pozostałych dostępów do Sejfu.
		 */
		size_t available_accesses;
	public:

		/*
		 * Konstruktor przyjmujący jako argument napis, który będzie przechowywany w sejfie,
		 * oraz być może ilość możliwych dostępów do sejfu.
		 */
		Sejf(String text, size_t available_accesses = 42);

		/*
		 * Operator umożliwiający dostęp do litery napisu o indeksie przekazanym w argumencie.
		 */
		char operator[](const size_t ind) const;
		
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
};
