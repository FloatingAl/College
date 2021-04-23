#include <string>
#include "ED.hpp"

//constructor
ED::ED(std::string str1, std::string str2){
  //basic assignment  
  _str1 = str1;
  _str2 = str2;

  _str1Len = str1.size();
  _str2Len = str2.size();

  //allocate for the first dimension
  _array = new int*[_str1Len + 1];//+1 because we assume the first column/row is empty

  //need to allocate 2nd dimension of array, <= because _array is (str1Len + 1

}

//get the penalty for comparing the args
int ED::penalty(char a, char b){

  //test = b - a;
  if(a == b)//check if chars are the same
    return 0;
  return 1;
}

//returns minimum of the three args, basic comparison
int ED::min(int a, int b, int c){
  if(a < b && a < c)
    return a;
  if(b < c)
    return b;
  else
    return c;
}

//traverses the 2d array, the meat of the program, have to move backwards (start at end)
/*int ED::optDistance(){
  //traverse from the end of the y-axis to the front

}

//traces the matrix and returns a string
std::string ED::alignment(){


}*/

int ED::getStr1Len(){
  return _str1Len;
}

int ED::getStr2Len(){
  return _str2Len;
}

ED::~ED(){
  //need to delete the memory we used for _array, this is second level
  //need to delete the first level
  delete[] _array;
}
