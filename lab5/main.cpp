#include <iostream>
#include "misc.cpp"

#include "dioda.h"
#include "kolor.h"
#include "rezystor.h"
#include "led.h"

int main()
{
  dioda dioda_1;
  dioda dioda_2(10, 0.25);

  std::cout << "Odczyt napięcia: " << dioda_1.odczytaj_Uf() << std::endl;
  std::cout << "Odczyt prądu: " << dioda_1.odczytaj_If() << std::endl;

  std::cout << "Stan diody dla Uzas=12V: " << std::endl;
  dioda_2.stan(12);

  br();

  rezystor rezystor_1;
  rezystor rezystor_2(2000);

  std::cout << "Odczyt rezystancji: " << rezystor_1.odczytaj() << std::endl;
  std::cout << "Ustawienie nowej rezystancji" << std::endl;
  rezystor_1.ustaw(3000);
  std::cout << "Odczyt rezystancji: " << rezystor_1.odczytaj() << std::endl;

  std::cout << "Stan rezystora dla Uzas=12V: " << std::endl;
  rezystor_2.stan(12);

  br();

  kolor czerwien(kolory::czerwony);
  kolor biel(kolory::bialy);

  std::cout << "Numer koloru dla czerwieni: " << static_cast<int>(czerwien.odczytaj()) << std::endl;
  std::cout << "Ustawienie nowego koloru " << std::endl;
  czerwien.ustaw(kolory::zielony);
  std::cout << "Numer nowego koloru: " << static_cast<int>(czerwien.odczytaj()) << std::endl;

  br();

  dioda_led led_1(12, 1, kolory::bialy, 4);
  dioda_led led_2(6, 1, kolory::zolty, 2);

  br();

  return 0;
}