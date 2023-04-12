#include <iostream>
#include <vector>
#include <typeinfo>

#include "colors.h"
#include "misc.cpp"
#include "zwierzak.h"
#include "pies.h"
#include "kot.h"

int main()
{
  br();

  // zwierzak Panda;
  // object of abstract class type "zwierzak" is not allowed

  br();

  pies Azor("Azor", 5);
  kot Filemon("Filemon", 3);

  br();

  // Azor.nazwa_odczytaj();
  // function "zwierzak::nazwa_odczytaj" is inaccessible

  br();

  Azor.daj_glos();
  Filemon.daj_glos();

  br();

  std::vector<zwierzak *> zwierzyniec;

  pies Reksio("Reksio", 7);
  pies Mika("Mika", 10);
  kot Kicia("Kicia", 6);

  zwierzyniec.push_back(&Reksio);
  zwierzyniec.push_back(&Mika);
  zwierzyniec.push_back(&Kicia);
  zwierzyniec.push_back(&Azor);
  zwierzyniec.push_back(&Filemon);

  for (auto zwierze : zwierzyniec)
    zwierze->daj_glos();

  br();

  for (auto zwierze : zwierzyniec)
  {
    if (typeid(*zwierze) == typeid(pies))
    {
      zwierze->daj_glos();
    }
  }

  br();

  for (auto zwierze : zwierzyniec)
  {
    if (typeid(*zwierze) == typeid(kot))
    {
      zwierze->daj_glos();
    }
  }

  br();

  for (auto zwierze : zwierzyniec)
  {
    kot *kotp = dynamic_cast<kot *>(zwierze);
    if (kotp)
    {
      kotp->daj_glos();
    }
    else
    {
      std::cout << RED << "Dynamiczne rzutowanie nie powiodło się" << CLEAR << std::endl;
    }
  }

  br();

  std::cout << Azor << std::endl;
  std::cout << Filemon << std::endl;

  br();

  return 0;
}