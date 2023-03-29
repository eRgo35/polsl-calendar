#include <iostream>
#include <sstream>
#include "counter.h"
#include "debug.h"
#include "colors.h"

void br()
{
  std::cout << ORANGE << "----------------------------" << CLEAR << std::endl;
}

int main(int argc, char *argv[])
{
  counter licznik;

  br();

  std::cout << "Wartość licznika: " << licznik.getCnt() << std::endl;

  licznik.setCnt(10);

  std::cout << "Wartość licznika po ustawieniu: " << licznik.getCnt() << std::endl;

  br();

  counter licznik1(10);
  counter licznik2(5);

  std::cout << "Wartość licznika 1: " << licznik1.getCnt() << std::endl;
  std::cout << "Wartość licznika 2: " << licznik2.getCnt() << std::endl;

  licznik1 = licznik2;

  std::cout << "Wartość licznika 1: " << licznik1.getCnt() << std::endl;  

  br(); 

  std::cout << "Wartość z int: " << (int) licznik1 << std::endl;
  std::cout << "Wartość z double: " << (double) licznik1 << std::endl;

  br();

  licznik1 += 89;
  std::cout << "counter += int: " << (int) licznik1 << std::endl;
  std::cout << "Suma counter + int: " << licznik1 + 99 << std::endl;
  std::cout << "Licznik po sumie pozostaje taki sam: " << (int) licznik1 << std::endl;
  std::cout << "Suma int + counter: " << 99 + licznik1 << std::endl;

  br();

  counter licznik3(0);

  std::cout << "Wartość licznika 3: " << (int) licznik3 << std::endl;
  
  licznik3();
   
  std::cout << "Wartość licznika 3: " << (int) licznik3 << std::endl;
  
  licznik3(11);
  
  std::cout << "Wartość licznika 3: " << (int) licznik3 << std::endl;

  br();

  ++licznik3;
  std::cout << "Preinkrementacja licznika 3: " << (int) licznik3 << std::endl;

  licznik3++;
  std::cout << "Postinkrementacja licznika 3: " << (int) licznik3 << std::endl;

  br();

  std::cout << "Negacja licznika3: " << (int) ~licznik3 << std::endl;

  br();

  std::cout << "Strumienie: " << licznik3 << std::endl;

  std::stringstream test("10");

  test >> licznik3;

  std::cout << "Przypisanie: " << licznik3 << std::endl;

  br();

  std::cout << "sprawdzenie resetu stanu licznika" << std::endl;

  counter licznik4(10);
  counter licznik5(5);

  std::cout << "Wartość licznika 4: " << licznik4.getCnt() << std::endl;
  std::cout << "Wartość licznika 5: " << licznik5.getCnt() << std::endl;

  licznik4 = licznik5;

  std::cout << "Wartość licznika 4: " << licznik4.getCnt() << std::endl;  
  std::cout << "Wartość licznika 5: " << licznik5.getCnt() << std::endl;  


  br();
  
  return 0;
}