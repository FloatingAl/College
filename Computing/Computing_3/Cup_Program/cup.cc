


#include <iostream>
#include <string>
#include "cup.h"


bool Cup::set_capacity(double arg) {
    capacity = arg;
    return true;
}

double Cup::get_capacity() {
  return capacity;
}

bool Cup::set_current_volume(double arg) {
    if (arg > 0 && arg < capacity) {
      current_volume = arg;
      return true;
    }
    else
      return false;
}

double Cup::get_current_volume() {
    return current_volume;
  }


bool Cup::pour_in(double arg) {
    if (arg > (capacity - current_volume)) {
      current_volume += arg;
      return true;
    }
    else {
      current_volume = capacity;
      return false;
    }
  }

bool Cup::pour_out(double arg) {
    return true;
  }

bool Cup::empty() {
    return pour_out(current_volume);
  }
