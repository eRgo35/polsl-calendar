#include <iostream>
#include "student.h"

int main(int argc, char *argv[])
{
  student test_student;

  // std::cout << test_student.imie << std::endl;
  // std::cout << test_student.nazwisko << std::endl;
  // std::cout << test_student.numer_legitymacji << std::endl;

  student mc_student("Michał", "Czyż", 123456);

  mc_student.wyswietl();
  mc_student.dodaj_srednia(5);

  student mc2_student(mc_student);

  mc2_student.wyswietl();

  return 0;
}
