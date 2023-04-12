#ifndef REKOPIS_H
#define REKOPIS_H

#include <iostream>
#include <vector>

#include "notatka.h"

class rekopis : public notatka
{
private:
  std::string tytul_roboczy;
  std::string recenzja;

protected:
  std::string tekst;
  std::vector<std::string> spis_tresci;

public:
  rekopis()
  {
    tytul_roboczy = "Wersja Robocza";
    recenzja = "Brak recenzji";
    tekst = "";
  }

  rekopis(std::string tytul)
  {
    tytul_roboczy = tytul;
    recenzja = "Brak recenzji";
    tekst = "";
  }

  rekopis(std::string tytul, std::string opinia, std::string zawartość)
  {
    tytul_roboczy = tytul;
    recenzja = opinia;
    tekst = zawartość;
  }

  friend std::ostream &operator<<(std::ostream &out, rekopis &rekopis)
  {
    std::cout << ORANGE << "Użycie operatora <<" << CLEAR << std::endl;
    out << "Treść: " << rekopis.getTresc() << std::endl
        << "Autor: " << rekopis.getAutor().nazwisko << " " << rekopis.getAutor().imie << std::endl
        << "Data: " << rekopis.getDate() << std::endl
        << "Tytuł Roboczy: " << rekopis.getTytul() << std::endl
        << "Recenzja: " << rekopis.getRecenzja() << std::endl
        << "Tekst: " << rekopis.getTekst() << std::endl
        << "Spis treści: " << std::endl;

    for (std::string spis : rekopis.getSpisTresci())
      out << spis << std::endl;

    return out;
  }

  std::string getTytul()
  {
    return tytul_roboczy;
  }

  std::string getTekst()
  {
    return tekst;
  }

  std::string getRecenzja()
  {
    return recenzja;
  }

  std::vector<std::string> getSpisTresci()
  {
    return spis_tresci;
  }

  void setTytul(std::string tytul)
  {
    tytul_roboczy = tytul;
  }

  void setTekst(std::string zawartosc)
  {
    tekst = zawartosc;
  }

  void setRecenzja(std::string opinia)
  {
    recenzja = opinia;
  }

  void setSpisTresci(std::vector<std::string> spis)
  {
    spis_tresci = spis;
  }
};

#endif