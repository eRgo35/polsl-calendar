#include <iostream>
#include "student.h"

int student::liczba_studentow = 0;

int main(int argc, char *argv[])
{
  student test_student;

  // test pól prywatnych
  // std::cout << test_student.imie << std::endl;
  // std::cout << test_student.nazwisko << std::endl;
  // std::cout << test_student.numer_legitymacji << std::endl;

  std::cout << "-----------------------------------" << std::endl;

  student mc_student("Michał", "Czyż", 123456);
  mc_student.dodaj_srednia(5);
  mc_student.wyswietl();

  std::cout << "-----------------------------------" << std::endl;

  student mc2_student(mc_student);
  mc2_student.wyswietl();
  mc_student.wyswietl();
  mc2_student.dodaj_srednia(3);
  mc2_student.wyswietl();

  std::cout << "-----------------------------------" << std::endl;

  student mc3_student(std::move(mc2_student));
  mc3_student.wyswietl();
  mc2_student.wyswietl(); // nie istnieje

  std::cout << "-----------------------------------" << std::endl;

  mc_student.wyswietl();
  mc_student.dodaj_srednia({3, 4, 5, 4, 2});
  mc_student.wyswietl();

  std::cout << "-----------------------------------" << std::endl;

  mc_student.setImie("Michael");
  mc_student.setNazwisko("Czyz");
  mc_student.setSemester(10);

  std::cout << "-----------------------------------" << std::endl;

  std::cout << mc_student.getImie() << std::endl;
  std::cout << mc_student.getNazwisko() << std::endl;
  std::cout << mc_student.getNumerLegitymacji() << std::endl;
  std::cout << mc_student.getSemestr() << std::endl;
  std::cout << mc_student.getSrednia() << std::endl;

  std::cout << "-----------------------------------" << std::endl;

  return 0;
}
