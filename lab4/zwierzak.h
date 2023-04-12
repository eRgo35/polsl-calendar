#ifndef ZWIERZAK_H
#define ZWIERZAK_H

#include <iostream>
#include "colors.h"

class zwierzak
{
private:
  const std::string nazwa;

protected:
  int wiek;

  std::string nazwa_odczytaj() const
  {
    return nazwa;
  }

  int wiek_odczytaj() const
  {
    return wiek;
  }

  void wiek_zapisz(int nowy_wiek)
  {
    wiek = nowy_wiek;
  }

public:
  zwierzak(std::string nazwa, int wiek) : nazwa(nazwa), wiek(wiek)
  {
    std::cout << RED << "Obiekt `zwierzak` utworzony pomyślnie" << CLEAR << std::endl;
  }

  ~zwierzak()
  {
    std::cout << RED << "Obiekt `zwierzak` zniszczony pomyślnie" << CLEAR << std::endl;
  }
  
  virtual void daj_glos() const = 0;

  virtual void wyswietl(std::ostream& os) const = 0;

  friend std::ostream& operator<<(std::ostream& os, zwierzak& zwierze)
  {
    zwierze.wyswietl(os);
    return os;
  }
};

#endif