#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>
#include <bitset>
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

  int operator=(counter &other)
  {
    cnt = other.cnt;
    other.setCnt(0);
    return cnt;
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

  int operator~()
  {
    return (0 - cnt);
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

  friend std::istream& operator>>(std::istream &is, counter &c)
  {
    int x;
    is >> x;
    c.setCnt(x);
    return is;
  }

  friend std::ostream& operator<<(std::ostream &os, counter &c)
  {
    os << c.getCnt();
    return os;
  }

  operator int() const
  {
    return cnt;
  }

  operator double() const
  {
    return (double)cnt;
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