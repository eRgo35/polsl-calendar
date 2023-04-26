#ifndef LED_H
#define LED_H

#include <iostream>
#include "dioda.h"
#include "kolor.h"
#include "rezystor.h"

class dioda_led : public virtual dioda, public kolor, public rezystor
{
public:
  dioda_led(double _Uf, double _If, kolory _kolor, double _R) : dioda(_Uf, _If), kolor(_kolor), rezystor(_R)
  {
    std::cout << BLUE << "Utworzono diodę LED" << CLEAR << std::endl;
  }

  ~dioda_led()
  {
    std::cout << BLUE << "Usunięto diodę LED" << CLEAR << std::endl;
  }

  void stan(double _Uzas)
  {
    std::cout << "" << std::endl;
  }
};

#endif