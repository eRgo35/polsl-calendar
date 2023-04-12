#ifndef NOTATKA_H
#define NOTATKA_H

#include <iostream>
#include <ctime>
#include <utility>

#include "colors.h"

std::time_t now = std::time(nullptr);

struct Autor
{
  std::string nazwisko;
  std::string imie;
  std::tm date;
};

class notatka
{
private:
  std::string tresc;

protected:
  Autor autor;

public:
  notatka()
  {
    tresc = "NULL";
    autor = {"Kowalski", "Jan", *std::localtime(&now)};
    std::cout << RED << "Utworzono notatkę" << CLEAR << std::endl;
  }

  notatka(std::pair<std::string, std::string> nazwisko_i_imie, std::tm data)
  {
    tresc = "NULL";
    autor = {nazwisko_i_imie.first, nazwisko_i_imie.second, data};
    std::cout << RED << "Utworzono notatkę" << CLEAR << std::endl;
  }

  friend std::ostream &operator<<(std::ostream &out, notatka &nota)
  {
    std::cout << ORANGE << "Użycie operatora <<" << CLEAR << std::endl;
    out << "Treść: " << nota.getTresc() << std::endl;
    out << "Autor: " << nota.getAutor().nazwisko << " " << nota.getAutor().imie << std::endl;
    out << "Data: " << nota.getDate();
    return out;
  }

  std::string getTresc()
  {
    return tresc;
  }

  Autor getAutor()
  {
    return autor;
  }

  std::string getDate()
  {
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &autor.date);

    return buffer;
  }
  
  void setTresc(std::string newTresc)
  {
    tresc = newTresc;
  }

  void setAutor(Autor newAutor)
  {
    autor = newAutor;
  }
};

#endif