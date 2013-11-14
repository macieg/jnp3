Tutaj jakieś uwagi na bieżąco + wazniejsze TODO.
===

1. Jak rozwiązać sprawę z kontrolerem(sugerowałbym klasę dodatkową zrobić,
jeżeli jest to możliwe)?

Mozliwe, dobry pomysl. Tylko pozniej uwazaj, zeby ja zalinkowac
tam, gdzie trzeba - wczesniej przez to byly problemy z kompilacja (i nie tylko).

Kontroler musi jeszcze moc byc uzyty jako wartosc logiczna. Dlatego powinien
wiedziec, ile jeszcze pozostalo dostepow, wiec przenioslem ten parametr
do kontrolera.

Kontroler jednak powinien nie miec metod set_manipulation i set_break_in
dostepnych publicznie, zeby nie bylo falszywych alarmow.
Dlatego zrobilem te metody prywatne.

2. "Sumy i Kontroler powinny być zabezpieczone(w zakresie, w którym jest to
możliwe w języku C++) przed modyfikacją ich stanu z zewnątrz"
Dodałem blokadę innych operatorów, słusznie?
Nie znam sie. Nie wiem tez, jak ktokolwiek mialby cokolwiek z tym zrobic, jesli
te klasy sa final, tzn to blokuje dopisanie klasy dziedziczacej i poustawianie
tam czegos wrednego. Ale jak uwazasz, ze to ma sens to mozna to zostawic.
Do końca nigdy nie ochronisz, bo zawsze możesz jechać po pamięci i czytać.

Na pewno = musi byc prywatny, bo on chyba jest jakos
Wyczytalem, ze np dlatego operator= daje sie jako prywatny, zeby ludzie tego
nie mogli kopiowac: wtedy kompilacja nie daje rady, bo po pierwsze probujesz
uzyc prywatna metode, a po drugie, nie zlinkuje sie bo nie ma dobrej definicji.

3. Zamieniłem size_t na inta tam, gdzie trzeba było. Mówili, żeby konstruktor
się wywalał po wywołaniu go z ujemną liczbą dostępów, więc trzeba było dać int,
a to pociągało za sobą inty gdziekolwiek indziej. Najładniejszy sposób, jaki
znalazłem, żeby ten sejf się wtedy nie zrobil to wyjątek.

Brakuje:
std::swap(); - nie bardzo wiem, jak to zrobić.
Testów na kontrolera. - to dopiero po swapie
W ogóle testów.
Zabieram się za SO.
