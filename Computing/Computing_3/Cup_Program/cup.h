
#ifndef CUP_H
#define CUP_H

#include <iostream>
#include <string>

using namespace std;

typedef enum {cold = 1, warm = 2, hot = 3} temperature_state;

class Cup 
{
private:
  double capacity;
  temperature_state temperature;
  string contents;
  double current_volume;

public:
  // default constructor: takes no arguments; remember that a default constructor is generated
  // for you if you do not define any constructors for your class
  Cup() {
    capacity = 100;
    temperature = cold;
  }

  // constructor
  Cup(double capacity_, double volume_, temperature_state temp_, string contents_) {
    capacity = capacity_;
    current_volume = volume_;
    temperature = temp_;
    contents = contents_;
  }
  
  bool set_capacity(double arg);
  double get_capacity();
  bool set_current_volume(double arg);
  double get_current_volume();
  bool pour_in(double arg);
  bool pour_out(double arg);
  bool empty();
};


#endif
