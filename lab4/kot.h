#ifndef KOT_H
#define KOT_H

#include <iostream>
#include "zwierzak.h"

class kot : public zwierzak
{
public:
  kot(std::string nazwa, int wiek) : zwierzak(nazwa, wiek)
  {
    std::cout << BLUE << "Obiekt `kot` utworzony pomyślnie" << CLEAR << std::endl;
  }

  ~kot()
  {
    std::cout << BLUE << "Obiekt `kot` zniszczony pomyślnie" << CLEAR << std::endl;
  }

  void daj_glos() const override
  {
    std::cout << "Meeeooow!" << std::endl;
  }

  void wyswietl(std::ostream &os) const override
  {
    os << "Kot " << nazwa_odczytaj() << " ma " << wiek_odczytaj() << " lat.";
  }
};

#endif