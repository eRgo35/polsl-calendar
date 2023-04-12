#ifndef PIES_H
#define PIES_H

#include <iostream>
#include "zwierzak.h"

class pies : public zwierzak
{
public:
  pies(std::string nazwa, int wiek) : zwierzak(nazwa, wiek)
  {
    std::cout << YELLOW << "Obiekt `pies` utworzony pomyślnie" << CLEAR << std::endl;
  }

  ~pies()
  {
    std::cout << YELLOW << "Obiekt `pies` zniszczony pomyślnie" << CLEAR << std::endl;
  }

  void daj_glos() const override
  {
    std::cout << "Woof, Woof!" << std::endl;
  }

  void wyswietl(std::ostream& os) const override
  {
    os << "Pies " << nazwa_odczytaj() << " ma " << wiek_odczytaj() << " lat.";
  }

};

#endif