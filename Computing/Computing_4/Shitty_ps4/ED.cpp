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

  //need to allocate 2nd dimension of array, <= because _array is (str1Len + 1)
  for(int i = 0; i <= _str1Len; ++i)
    _array[i] = new int[_str2Len + 1];//need str2Len + 1 b/c first column/row is empty

  //populate the array
  for(int j = 0; j <= _str1Len; ++j)
    _array[j][_str2Len] = (_str1Len - j) * 2;

  for(int k = 0; k <= _str2Len; ++k)
    _array[_str1Len][k] = (_str2Len - k) * 2;

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
int ED::optDistance(){
  //traverse from the end of the y-axis to the front
  for(int i = _str2Len-1; i >= 0; --i){
    //traverse from the end of the x-axis to the front
    for(int j = _str1Len-1;j >= 0; --j){
      //figure out the penalty
      if(!(penalty(_str1[j], _str2[i])))
	_array[j][i] = _array[j+1][i+1];
      else
	_array[j][i] = min(_array[j][i+1] + 2, _array[j+1][i] + 2, _array[j+1][i+1] + 1);
    }

  }
  return _array[0][0];
}

//traces the matrix and returns a string
std::string ED::alignment(){
  std::string temp;

  int i = 0;
  int j = 0;

  //used for concatinating values to be printed
  std::string zero = "0";
  std::string one = "1";
  std::string two = "2";
  std::string dash = "-";

  while(i < _str1Len || j < _str2Len){
    //if the chars are the same, penalty is 0
    if(!(penalty(_str1[i], _str2[j]))){
      temp = temp + _str1[i] + _str2[j] + zero;
      i++;
      j++;
    }
    //else if there is a dash in the second string, penalty is 2
    else if(_array[i][j] == (_array[i+1][j] + 2)){
      temp = temp  +  _str1[i] + dash + two;
      i++;
    }
    //else if there is a dash in the first string, penalty is 2
    else if(_array[i][j] == (_array[i][j+1] + 2)){
      temp = temp + dash + _str2[j] + two;
      j++;
    }
    //else there are two different chars, penalty is 1
    else{
      temp = temp + _str1[i] + _str2[j] + one;
      i++;
      j++;
    }
  }
  
  //return the new string
  return temp;

}

int ED::getStr1Len(){
  return _str1Len;
}

int ED::getStr2Len(){
  return _str2Len;
}

ED::~ED(){
  //need to delete the memory we used for _array, this is second level
  for(int i = 0; i < _str1Len; i++)
    delete[] _array[i];
  //need to delete the first level
  delete[] _array;
}
