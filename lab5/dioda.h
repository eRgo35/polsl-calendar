#ifndef DIODA_H
#define DIODA_H

#include <iostream>
#include "colors.h"

class dioda
{
private:
  double Uf, If;

public:
  dioda() : Uf(5), If(0.2)
  {
    std::cout << RED << "Utworzono diodę" << CLEAR << std::endl;
    std::cout << "Parametry domyślne: Uf=" << Uf << "V If=" << If << "A" << std::endl;
  }

  dioda(double _Uf, double _If) : Uf(_Uf), If(_If)
  {
    std::cout << RED << "Utworzono diodę z parametrami" << CLEAR << std::endl;
    std::cout << "Parametry: Uf=" << Uf << "V If=" << If << "A" << std::endl;
  }

  ~dioda()
  {
    std::cout << RED << "Usunięto diodę" << CLEAR << std::endl;
  }

  double odczytaj_Uf(void)
  {
    return Uf;
  }

  double odczytaj_If(void)
  {
    return If;
  }

  void stan(double _Uzas)
  {
    std::cout << "Uf=  If=  " << std::endl;
  }
};

#endif