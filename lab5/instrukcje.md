# Zadanie 5
## Dziedziczenie wielobazowe

Kazda klasa w oddzielnym pliku naglowkowym/implementacyjnym
W kazdym konstruktorze/destruktorze raportowac na cout (clog) jego wywolanie
Po zadeklarowaniu kazdej klasy (wybranego elementu) utworzyc obiekt i przetestowac dzialanie

1. [ ] Utworzyć następujšce klasy z polami/atrybutami i metodami:
  KLASA dioda
  ==================
      private:
	     double Uf, If;
      public:
	     dioda();
	     dioda(double _Uf, double _If);
	     ~dioda();

       double odczytaj_Uf(void);
       double odczytaj_If(void);
       void stan(double _Uzas);

  KLASA kolor
  ==================
      private:
       kolory jaki_kolor;

      public:
	      kolor(kolory _jaki_kolor);
	     ~kolor();

     void ustaw(kolory _jaki_kolor);
     kolory odczytaj();

    gdzie kolory to klasa enum zadeklarowana jako
        enum class kolory {bialy, zolty, ...};

  KLASA rezystor (dioda)
  ==================
      private:
	     double R;
      public:
	     rezystor();
	     rezystor(double _R);
	     ~rezystor();

	     void ustaw(double _R);
	     double odczytaj(void);
	     void stan(double _Uzas);

  KLASA dioda_led (dioda, kolor, rezystor)
  ==================
      public:
       dioda_led(double _Uf, double _If, kolory _kolor, double _R);
       ~dioda_led();
       
       void stan(double _Uzas);
