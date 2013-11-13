Tutaj jakieś uwagi na bieżąco + wazniejsze TODO.
===

1. Jak rozwiązać sprawe swapa?


2. Jak rozwiązać sprawę z kontrolerem(sugerowałbym klasę dodatkową zrobić,
jeżeli jest to możliwe)?

Mozliwe, dobry pomysl. Tylko pozniej uwazaj, zeby ja zalinkowac
tam, gdzie trzeba - wczesniej przez to byly problemy z kompilacja (i nie tylko).

3. "Sumy i Kontroler powinny być zabezpieczone(w zakresie, w którym jest to
możliwe w języku C++) przed modyfikacją ich stanu z zewnątrz"
Dodałem blokadę innych operatorów, słusznie?

Inaczej nie widze mozliwosci, trzeba po prostu zablokowac wszystkie gettery
i cokolwiek, co moze modyfikowac.
Dodalem też "final", żeby nikt nie mógł po prostu dać klasy dziedziczącej po
niej i zrobić czegoś wrednego z tamtego poziomu. Do końca nigdy nie ochronisz,
bo zawsze możesz jechać po pamięci i czytać.

Wyczytalem, ze np dlatego operator= daje sie jako prywatny, zeby ludzie tego
nie mogli kopiowac: wtedy kompilacja nie daje rady, bo po pierwsze probujesz
uzyc prywatna metode, a po drugie, nie zlinkuje sie bo nie ma dobrej definicji.
