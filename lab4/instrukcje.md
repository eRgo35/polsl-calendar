# Zadanie 4
## Polimorfizm

Kazda klasa w oddzielnym pliku naglowkowym/implementacyjnym
W kazdym konstruktorze/destruktorze raportowac na cout (clog) jego wywolanie
Po zadeklarowaniu kazdej klasy (wybranego elementu) utworzyc obiekt i przetestowac dzialanie

1. [x] Zadeklarowac abstrakcyjna klase zwierzak zawiarajaca:
   - [x] pole prywatne nazwa (const string)
   - [x] pole protected wiek (int lub double)
   - [x] metody (protected lub public): nazwa_odczytaj, wiek_odczytaj, wiek_zapisz,
   - [x] konstruktor (dwuargumentowy pozwalajacy ustawic nazwe i wiek) oraz destruktor,
   - [x] publiczna wirtualna metode zerowa daj_glos.
   [czy mozna zdefiniowac obiekt typu zwierzak?] - Nie.

2. - [x] Wyprowadzic z klasy zwierzak klase potomna pies oraz  kot, 
   - [x] utworzyc konstruktor/destruktor oraz uzupelnic metode daj_glos
   - [x] w programie glownym zdefiniowac obiekty typu pies i kot oraz przetestowac dzialanie wybranych metod.

3. - [x] Zdefiniowac wektor (zwierzyniec) wskaznikow na obiekty klasy zwierzak oraz dodac do niego kilka obiektow typu pies oraz kot 
   - [x] przetestowac dzialanie metody daj_glos wywolujac ja dla kolejnych obiektow zawartych w wektorze [jak sprawdzic z jakiej klasy pochodzi dany obiekt?] - typeid.
   - [x] wywolac metode daj_glos najpierw dla wszystkich obiektow klasy pies, a nastepnie dla wszystkich obiektow klasy kot (wykorzystac mechanizm RTTI tj. operator typeid zwracajacy wartosc type_info).

5. [x] Napisac fragment kodu probujacy zmienic zawartosc kazdego elementu wektora (wskazniki na obiekty klasy zwierzak) na typ kot* z wykorzystaniem rzutowania dynamic_cast wraz ze sprawdzeniem, czy takie rzutowanie zostalo przeprowadzone poprawnie (wyswietlic odpowiedni komunikat).

6. [ ] Zdefiniowac, dla opracowanych klas, wirtualny operator wyjscia <<, pozwalajacy wyprowadzic na konsole informacje o kazdym elemencie wektora np. cout << *zwierzyniec[0]
   Uwaga: Operator << jest zdefiniowany w klasie ostream i nie da sie go wprost zrealizowac jako wirtualny, trzeba zadeklarowac w klasie bazowej metode wirtualna wyswietl (zerowa), ktora bedzie zdefiniowana w klasach pochodnych i ja wykorzystac w zaprzyjaznionej metodzie operatorowej zadeklarowanej w klasie podstawowej.