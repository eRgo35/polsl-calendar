#ifndef KSIAZKA_H
#define KSIAZKA_H

#include <iostream>
#include <vector>

#include "rekopis.h"
#include "colors.h"

class ksiazka final : public rekopis
{
private:
  std::string wydawnictwo;
  int numer_wydania;
  int rok_wydania;
  std::string numer_isbn;

public:
  ksiazka() : wydawnictwo("PWN"), numer_wydania(1), rok_wydania(2023), numer_isbn("00000000")
  {
    std::cout << ORANGE << "Użyto konstruktora bezargumentowego" << CLEAR << std::endl;
  }

  ksiazka(std::string wydawnictwo, int numer_wydania, int rok_wydania, std::string numer_isbn) : wydawnictwo("PWN"), numer_wydania(1), rok_wydania(2023), numer_isbn("00000000")
  {
    std::cout << ORANGE << "Użyto konstruktora wieloargumentowego" << CLEAR << std::endl;
  }

  ~ksiazka()
  {
    std::cout << RED << "Zniszczono notatkę" << CLEAR << std::endl;
  }

  friend std::ostream &operator<<(std::ostream &out, ksiazka &ksiazka)
  {
    std::cout << ORANGE << "Użycie operatora <<" << CLEAR << std::endl;
    out << "Treść: " << ksiazka.getTresc() << std::endl
        << "Autor: " << ksiazka.getAutor().nazwisko << " " << ksiazka.getAutor().imie << std::endl
        << "Data: " << ksiazka.getDate() << std::endl
        << "Tytuł Roboczy: " << ksiazka.getTytul() << std::endl
        << "Recenzja: " << ksiazka.getRecenzja() << std::endl
        << "Tekst: " << ksiazka.getTekst() << std::endl
        << "Spis treści: " << std::endl;

    for (std::string spis : ksiazka.getSpisTresci())
      out << spis << std::endl;

    out << "Wydawnictwo: " << ksiazka.getWydawnictwo() << std::endl
        << "Numer wydania: " << ksiazka.getNumerWydania() << std::endl
        << "Rok wydania: " << ksiazka.getRokWydania() << std::endl
        << "Numer ISBN: " << ksiazka.getISBN() << std::endl;

    return out;
  }

  std::string getWydawnictwo()
  {
    return wydawnictwo;
  }

  int getNumerWydania()
  {
    return numer_wydania;
  }

  int getRokWydania()
  {
    return rok_wydania;
  }

  std::string getISBN()
  {
    return numer_isbn;
  }

  void setWydawnictwo(std::string w)
  {
    wydawnictwo = w;
  }

  void setNumerWydania(int nr)
  {
    numer_wydania = nr;
  }

  void setRokWydania(int rok)
  {
    rok_wydania = rok;
  }

  void setISBN(std::string isbn)
  {
    numer_isbn = isbn;
  }
};

#endif