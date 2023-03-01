#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class student
{
private:
  std::string nazwisko;
  std::string imie;
  const int numer_legitymacji;
  int semestr;
  int *srednia;

public:
  static int utworzone_obiekty;

  student() : numer_legitymacji(0)
  {
    this->imie = "Jan";
    this->nazwisko = "Kowalski";

    std::cout << "Objekt `Jan Kowalski` utworzony pomyślnie!" << std::endl;
  }

  student(std::string imie, std::string nazwisko, int numer_legitymacji) : numer_legitymacji(numer_legitymacji)
  {
    this->imie = imie;
    this->nazwisko = nazwisko;

    std::cout << "Objekt `" << imie << " " << nazwisko << "` utworzony pomyślnie!" << std::endl;
  }

  student(const student &inny)
      : nazwisko(inny.nazwisko),
        imie(inny.imie),
        numer_legitymacji(inny.numer_legitymacji),
        semestr(inny.semestr)
  {
    std::cout << "Kopia utworzona pomyślnie" << std::endl;
  }

  ~student()
  {
    delete this->srednia;
    std::cout << "Objekt zniszczony pomyślnie!" << std::endl;
  }

  void dodaj_srednia(int srednia)
  {
    std::cout << "Średnia dla semestru " << this->semestr << " to " << srednia << std::endl;
  }

  void wyswietl()
  {
    std::cout << "Imię: " << imie << std::endl;
    std::cout << "Nazwisko: " << nazwisko << std::endl;
    std::cout << "Numer legitymacji: " << numer_legitymacji << std::endl;
    std::cout << "Semestr: " << semestr << std::endl;
  }
};

#endif