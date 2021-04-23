

#include <iostream>
#include <string>
#include <cmath>


class LFSR {
  
public:
  LFSR(std::string seed_, int tap_);
  ~LFSR();
  int step();
  int generate(int k);

  friend std::ostream& operator<< (std::ostream &out, LFSR &lfsr);

private:
  std::string seed;
  int tap;
};

