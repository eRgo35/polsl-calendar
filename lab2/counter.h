#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>
#include "colors.h"

class counter
{
private:
  int cnt;

public:
  counter()
  {
    cnt = 0;
    std::cout << BLUE << "Licznik utworzony" << CLEAR << std::endl;
  }

  counter(int i)
  {
    cnt = i;
    std::cout << BLUE << "Licznik utworzony z wartością " << i << CLEAR << std::endl;
  }

  ~counter()
  {
    std::cout << RED << "Licznik zniszczony" << CLEAR << std::endl;
  }

  void operator=(const counter& other)
  {
    cnt = other.cnt;
  }

  int operator+=(const int x)
  {
    cnt += x;
    return cnt;
  }

  int operator+(const int x)
  {
    return cnt + x;
  }

  void operator~()
  {
    cnt = 0 - cnt;
  }

  void operator()()
  {
    cnt++;
  }

  void operator()(int x)
  {
    cnt += x;
  }

  void operator++()
  {
    ++cnt;
  }
  
  void operator++(int)
  {
    cnt++;
  }
  
  operator int() const
  {
    return cnt;
  }

  operator double() const
  {
    return (double) cnt;
  }

  int getCnt()
  {
    return cnt;
  }

  void setCnt(int i)
  {
    cnt = i;
  }
};

int operator+(int x, counter &c)
{
  return x + c.getCnt();
}

#endif