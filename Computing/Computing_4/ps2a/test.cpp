
#include "LFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(fiveBitsTapAtTwo) {
  //steps through the function 8 times and checks to see the return bit is 1 or 0.	
  LFSR l("00111", 2);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);

  //Doing the math, it turns out to 198
  LFSR l2("00111", 2);
  BOOST_REQUIRE(l2.generate(8) == 198);

}

BOOST_AUTO_TEST_CASE(Test1){
	 // I stepped 5 times by doing the xor to the 2nd tap.
  LFSR l3("0110110", 2);
  BOOST_REQUIRE(l3.step() == 1);
  BOOST_REQUIRE(l3.step() == 0);
  BOOST_REQUIRE(l3.step() == 1);
  BOOST_REQUIRE(l3.step() == 1);
  BOOST_REQUIRE(l3.step() == 1);

}
BOOST_AUTO_TEST_CASE(Test2){
  //goes  through step 3 times and by doing it out by hand, the answer is 7
  //It steps 3 times.
  LFSR l4("0110001", 3);
  BOOST_REQUIRE(l4.generate(4) == 7);
}


