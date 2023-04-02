# Zadanie 3

Kazda klasa w oddzielnym pliku naglowkowym/implementacyjnym
W kazdym konstruktorze/destruktorze raportowac na cout (clog) jego wywolanie
Raportować na cout (clog) w każdym operatorze jego uzycie 
Po zadeklarowaniu klasy (wybranego elementu) utworzyc obiekt i przetestowac dzialanie

1. [x] Zadeklarowac klase bazowa notatka zawierajaca:
  - [x] pole prywatne: tresc (string),
  - [x] pola chronione: autor (struktora zawierajaca nazwisko (string) i imie (string) oraz date (np. tm z biblioteki ctime),
  - [x] metody publiczne: 
    * konstruktor bezargumentowy (ustawiajacy pola w domyslne wartosci 
       z biezaca data) i dwuargumentowy (pozwalajacy okreslic nazwisko
       i imie, data biezaca),
    * przeciazony operator << wypisujacy informacje o notatce tj. autora,
       date utworzenia oraz tresc notatki;
    
2. [ ] Zadeklarowac klase rekopis wyprowadzona z klasy notatka, uzupelniona o:
  - [ ] pola prywatne: tytul_roboczy (string) i recenzja (string),
  - [ ] pola chronione: tekst (string) i spis_tresci (vector<string>),
  - [ ] metody publiczne:
    * konstruktor bezargumentowy (ustawiajacy pola w domyslne wartosci), 
      jednoargumentowy (ustawiajacy tytul roboczy), trojargumentowy (tytul 
      roboczy, nazwisko, imie), destruktor,
    * metody umozliwiajace dodanie tytulu, tekstu, spisu tresci oraz tekstu recenzji,
  - [ ] dla obiektu klasy rekopis sprawdzic dzialanie operatora << dla strumienia cout tzn. cout << obiekt_klasy_rekopis,
  - [ ] przedefiniowac operator <<, tak by wyswietlane byly informacje jak dla klasy notatka oraz dodatkowo pola zawarte w klasie rekopis;

3. Zadeklarowac ostateczna klase ksiazka wyprowadzona z klasy rekopis, uzupelniona o:
  - [ ] pola prywatne: wydawnictwo (string), numer_wydania (int), rok_wydania (int), numer isbn (string),
  - [ ] metody publiczne:
    * konstruktor bezargumentowy (ustawiajacy pola w domyslne wartosci), 
      wieloargumentowy (pozwalajacy ustawic wszystkie pola z klasy ksiazka),
      destruktor,
    * metody pozwalajace ustawic pola prywatne klasy ksiazka,
    * przeciazyc operator <<, tak by mozliwe bylo wyswietlenie na konsoli
      zawartosci ksiazki, tj. strony tytulowej, spisu tresci oraz tresci;
    
4. Zadanie domowe (dodatkowe):
  - [ ] uzupelnic klasy o konstruktory kopiujace/przenoszace oraz operatory przypisania/przenoszenia, sprawdzic ich dzialanie na obiektach,
  - [ ] rozbudowac klasy o metody get/set dla wszystkich pol.
