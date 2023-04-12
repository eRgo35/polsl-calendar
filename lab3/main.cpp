#include <iostream>

#include "colors.h"
#include "misc.cpp"
#include "notatka.h"
#include "rekopis.h"
#include "ksiazka.h"

int main()
{
  notatka nota1;

  std::cout << "Treść: " << nota1.getTresc() << std::endl;
  std::cout << "Autor: " << nota1.getAutor().imie << " " << nota1.getAutor().nazwisko << std::endl;
  print_time(nota1.getAutor().date);

  br();

  std::pair<std::string, std::string> nazw_i_imie;
  struct tm data { 0 };

  data.tm_year = 2022 - 1900;
  data.tm_mon = 4;
  data.tm_mday = 16;

  nazw_i_imie = {"Janusz", "Nowak"};

  notatka nota2(nazw_i_imie, data);

  std::cout << "Treść: " << nota2.getTresc() << std::endl;
  std::cout << "Autor: " << nota2.getAutor().imie << " " << nota2.getAutor().nazwisko << std::endl;
  print_time(data);

  br();

  std::cout << nota2 << std::endl;

  br();

  rekopis skrypt;
  std::cout << "Informacje o rękopisie: " << skrypt.getTytul() << "; " << skrypt.getRecenzja() << std::endl;

  br();

  std::cout << skrypt << std::endl;

  br();

  ksiazka ksiega;
  std::cout << ksiega << std::endl;

  br();

  return 0;
}