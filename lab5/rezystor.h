#ifndef REZYSTOR_H
#define REZYSTOR_H

#include <iostream>
#include "dioda.h"

class rezystor : public virtual dioda
{
private:
  double R;

public:
  rezystor() : R(1000)
  {
    std::cout << YELLOW << "Utworzono rezystor" << CLEAR << std::endl;
    std::cout << "Parametr domyślny: R=" << R << "ꭥ" << std::endl;
  }

  rezystor(double _R) : R(_R)
  {
    std::cout << YELLOW << "Utworzono rezystor z parametrem" << CLEAR << std::endl;
    std::cout << "Parametr: R=" << R << "ꭥ" << std::endl;
  }

  ~rezystor()
  {
    std::cout << YELLOW << "Usunięto rezystor" << CLEAR << std::endl;
  }

  void ustaw(double _R)
  {
    R = _R;
  }

  double odczytaj(void)
  {
    return R;
  }

  void stan(double _Uzas)
  {
    std::cout << "R=  Ur=  Ir=  " << std::endl;
  }
};

#endif