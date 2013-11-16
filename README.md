Tutaj jakieś uwagi na bieżąco + wazniejsze TODO.
===

1. Zmieniłem koncepcję nieco. Wszystkie zmienne trzymane są w Sejfie, zaś Kontroler trzyma wskaźnik na swój sejf.
Dlaczego? Ponieważ bo wykonaniu auto k1 = sejf.kontroler(); tworzy nam się kopia kontrolera i w efekcie gdy robimy zmiany na
sejfie to kontroler tego nie widzi (tak jak w tescie przykladowym).

Brakuje:
std::swap(); - nie bardzo wiem, jak to zrobić.
Testów na kontrolera. - to dopiero po swapie
W ogóle testów.
Zabieram się za SO.
