
#include "cup.h"

int main() {
  Cup c;
  Cup d(200, 50, hot, "milk");
  d.pour_in(10.5);
  //d.current_volume = 250;
  if (d.set_current_volume(250)) 
    cout << "success!" << endl;
}
