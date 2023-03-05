#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <initializer_list>

class student
{
private:
  std::string nazwisko;
  std::string imie;
  const int numer_legitymacji;
  int semestr;
  int *srednia;
  static int liczba_studentow;

public:
  student() : nazwisko("Nowak"), imie("Jan"), numer_legitymacji(0), semestr(0), srednia(new int[semestr + 1])
  {
    std::cout << "\033[1;34mObjekt `" << this->imie << " " << this->nazwisko << " " << this->numer_legitymacji << "` utworzony pomyślnie!" << "\033[0m" << std::endl;
    std::cout << "\033[1;31mLiczba studentów: " << ++liczba_studentow << "\033[0m" << std::endl;
  }

  student(std::string imie, std::string nazwisko, int numer_legitymacji) : nazwisko(nazwisko), imie(imie), numer_legitymacji(numer_legitymacji), semestr(0), srednia(new int[semestr + 1])
  {
    std::cout << "\033[1;34mObjekt `" << this->imie << " " << this->nazwisko << " " << this->numer_legitymacji << "` utworzony pomyślnie!" << "\033[0m" << std::endl;
    std::cout << "\033[1;31mLiczba studentów: " << ++liczba_studentow << "\033[0m" << std::endl;
  }

  student(const student &inny) : nazwisko(inny.nazwisko), imie(inny.imie), numer_legitymacji(inny.numer_legitymacji), semestr(inny.semestr), srednia(new int[semestr])
  {
    for (int i = 0; i < semestr; i++)
    {
      srednia[i] = inny.srednia[i];
    }
    std::cout << "\033[1;33mKopiowanie zakończone pomyślnie!" << "\033[0m" << std::endl;
    std::cout << "\033[1;31mLiczba studentów: " << ++liczba_studentow << "\033[0m" << std::endl;
  }

  student(student &&inny) : nazwisko(std::move(inny.nazwisko)), imie(std::move(inny.imie)), numer_legitymacji(std::move(inny.numer_legitymacji)), semestr(std::move(inny.semestr)), srednia(std::move(inny.srednia))
  {
    // niezbędne bo inaczej jest segfault albo double free error
    inny.semestr = 0;
    inny.srednia = nullptr;

    std::cout << "\033[1;33mPrzenoszenie zakończone pomyślnie!" << "\033[0m" << std::endl;
    std::cout << "\033[1;31mLiczba studentów: " << ++liczba_studentow << "\033[0m" << std::endl;
  }

  ~student()
  {
    delete[] srednia;
    std::cout << "\033[1;34mObjekt `" << this->imie << " " << this->nazwisko << "` zniszczony pomyślnie!" << "\033[0m" << std::endl;
    std::cout << "\033[1;31mLiczba studentów: " << --liczba_studentow << "\033[0m" << std::endl;
  }

  void dodaj_srednia(int srednia)
  {
    this->srednia[this->semestr] = srednia;
    std::cout << "Średnia dla semestru " << this->semestr++ << " to " << srednia << std::endl;
  }

  void dodaj_srednia(std::initializer_list<int> srednie)
  {
    for (auto srednia : srednie)
      this->srednia[this->semestr++] = srednia;
    std::cout << "Dodano średnie" << std::endl;
  }

  void wyswietl()
  {
    std::cout << "Imię: " << imie << std::endl;
    std::cout << "Nazwisko: " << nazwisko << std::endl;
    std::cout << "Numer legitymacji: " << numer_legitymacji << std::endl;
    std::cout << "Semestr: " << semestr << std::endl;
    std::cout << "Średnie: ";
    for (int i = 0; i < semestr; i++)
    {
      std::cout << srednia[i] << " ";
    }
    std::cout << std::endl;
  }

  // Getters
  std::string getNazwisko() const {
    return this->nazwisko;
  }

  std::string getImie() const {
    return this->imie;
  }

  int getNumerLegitymacji() const {
    return this->numer_legitymacji;
  }

  int getSemestr() const {
    return this->semestr;
  }

  int *getSrednia() const {
    return this->srednia;
  }

  // Setters
  void setNazwisko(std::string nazwisko)
  {
    this->nazwisko = nazwisko;
  }

  void setImie(std::string imie)
  {
    this->imie = imie;
  }

  void setSemester(int semestr)
  {
    this->semestr = semestr;
  }

  // numeru legitymacji, oraz srednich nie możemy ustawiać bo mają dedykowane funkcje

};

#endif