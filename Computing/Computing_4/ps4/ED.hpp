#ifndef ED_H
#define ED_H

#include <string>
#include <iostream>
#include <algorithm>
#include <SFML/System.hpp>

class ED{
private:
  std::string _str1;
  int _str1Len;
  std::string _str2;
  int _str2Len;

  int **_array;

public:
  ED(std::string str1, std::string str2);//constructor, allocates any data structures

  static int penalty(char a, char b);//returns penaluty for aligning chars(0 or 1)

  static int min(int a, int b, int c);//returns minimum of 3 args

  int optDistance();//populates matricies based on two strings, returns optimal discance

  std::string alignment();//traces the matrix and returns string to be printed

  int getStr1Len();

  int getStr2Len();

  ~ED();

};

#endif
