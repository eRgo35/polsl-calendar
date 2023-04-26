#ifndef KOLOR_H
#define KOLOR_H

#include <iostream>
#include <vector>

enum class kolory
{
  bialy,
  zolty,
  czerwony,
  niebieski,
  zielony
};

std::vector<std::string> nazwy_kolorow = {
    "biały",
    "żółty",
    "czerwony",
    "niebieski",
    "zielony"};

class kolor
{
private:
  kolory jaki_kolor;

  std::string odczytaj_nazwe(kolory _jaki_kolor)
  {
    return nazwy_kolorow[static_cast<int>(_jaki_kolor)];
  }

public:
  kolor(kolory _jaki_kolor) : jaki_kolor(_jaki_kolor)
  {
    std::cout << GREEN << "Utworzono kolor" << CLEAR << std::endl;
    std::cout << "Kolor: " << odczytaj_nazwe(jaki_kolor) << std::endl;
  }

  ~kolor()
  {
    std::cout << GREEN << "Usunięto kolor" << std::endl;
  }

  void ustaw(kolory _jaki_kolor)
  {
    jaki_kolor = _jaki_kolor;
  }

  kolory odczytaj()
  {
    return jaki_kolor;
  }
};

#endif