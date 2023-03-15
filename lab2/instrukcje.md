# Zadanie 2.

Zadeklarowac Klase counter (licznik) posiadajaca pola/metody opisane ponizej. Zdefiniowac w programie obiekty klasy counter oraz przetestowac opracowane metody. W metodach wyprowadzac informacje na konsole o wywolaniu danej metody (konstruktora/destruktora, operatora itp.).

Deklaracje klasy counter umiescic w pliku naglowkowym *.h, natomiast definicje w pliku implementacyjnym *.cpp.
  1. [x] Zadeklarowac pole cnt przechowujace zawartosc licznika.
  2. [x] Dodac do klasy konstruktor bezargumentowy/z argumentem domyslnym inicjujacy pole cnt oraz metody get/set.
  3.  Opracowac nastepujace metody (operatory przeladowane)
      - [x] operator przypisania =,
      - [x] konwersji z counter na int oraz counter na double,
      - [x] operator dodawania (counter += int, counter + int, int + counter) [ktory z nich wymaga zaprzyjaznienia z klasa 
        i dlaczego?],
      - [x] operator () (bez argumentu inkrementuje zawartosc licznika o 1, z argumentem - o podana wartosc),
      - [x] operatory post- i pre- inkremetacji (++counter, counter++),
      - [ ] operator negacji (~counter),
      - [ ] operatory << oraz >> do wyswietlania i pobierania zawartosci licznika ze standardowych strumieni cout i cin [dlaczego 
        wymagaja zaprzyjaznienia?], wyswietlanie zawartosci w postaci np. 8-bitowej liczby binarnej (mozna wykorzystac funkcje 
        bitset - trzeba dolaczyc plik naglowkowy <bitset>),
      - [ ] operator przeniesienia zawartosci licznika (w przypadku pola statycznego, po przeniesieniu, mozna wyzerowac licznik 
        zrodlowy).