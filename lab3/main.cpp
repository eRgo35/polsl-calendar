#include <iostream>
#include <ctime>
#include <utility>

#include "colors.h"
#include "notatka.h"

void br()
{
  std::cout << GREEN << "----------------------------" << CLEAR << std::endl;
}

void print_time(std::tm date)
{
  char buffer[100];
  strftime(buffer, sizeof(buffer), "%Y-%m-%d", &date);

  std::cout << buffer << std::endl;
}

int main()
{
  notatka nota1;

  std::cout << "Treść: " << nota1.getTresc() << std::endl;
  std::cout << "Autor: " << nota1.getAutor().imie << " " << nota1.getAutor().nazwisko << std::endl;
  print_time(nota1.getAutor().date);

  br();

  std::pair<std::string, std::string> nazw_i_imie;
  std::tm data{
      .tm_year = 2020 - 1900,
      .tm_mon = 4 - 1,
      .tm_mday = 30,
  };

  nazw_i_imie = {"Janusz", "Nowak"};

  notatka nota2(nazw_i_imie, data);

  std::cout << "Treść: " << nota2.getTresc() << std::endl;
  std::cout << "Autor: " << nota2.getAutor().imie << " " << nota2.getAutor().nazwisko << std::endl;
  print_time(data);

  br();

  return 0;
}