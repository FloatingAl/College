//Created a default constructor 
//line 89, vectors needs 4 numbers instead of 2
//line 52, didnt have a function call and each vector has 2 points with a x and y.
//line 36, changed the getters to a const because to not have it change

#include <iostream>

using namespace std;

class Point {
private:
  double x;
  double y;
public:
  double get_x() const { return x; }
  double get_y() const { return y; }
  bool set_x(double arg) { 
    x = arg; 
    return true;
  }
  bool set_y(double arg) { 
    y = arg; 
    return true;
  }
  Point() : x(0), y(0) {}
  Point(double argx, double argy) : x(argx), y(argy) {
  }
};


class Vector {
private:
  Point A;
  Point B;
public:
  Point get_A() { return A; }
  Point get_B() { return B; }
 
  Vector(){
  }

  Vector(const Point &arg1, const Point &arg2) : A(arg1), B(arg2) 
  {
    //this->A = arg1;
    //this->B = arg2;
    //A = arg1;
    //B = arg2;
  }
  void set_A(const Point &arg) {
    A = arg;
  }
  void set_B(const Point &arg) {
    B = arg;
  }
  static Vector add_vector(const Vector &vector1, const Vector &vector2) {
    if ( ! (vector1.B.get_x() == vector2.A.get_x() && vector1.B.get_y() == vector2.A.get_y() ) ) {
      Vector rval;
      return rval;
    }

    Point one = vector1.A;
    Point two = vector2.B;

    Vector newvector(one, two);
    //newvector.A = one;
    //newvector.B = two;
    return newvector;

  }
/*
  Vector add_vector(const Vector &arg) {
    // Type of this?  Vector *; These three lines are equivalent:
    //Point one = this->A;
    //Point one = (*this).A;
    Point one = A;

    Point two = arg.B;

    Vector newvector(one, two);
    //newvector.A = one;
    //newvector.B = two;
    return newvector;
  }
*/
};


int main() {
  Vector v;
  cout << "(" << v.get_A().get_x() << ", " << v.get_A().get_y() << "),\n" << 
        "(" << v.get_B().get_x() << ", " << v.get_B().get_y() << ")\n";

  Vector v1(Point(0,0), Point(1,2)), v2(Point(0,0),Point(2,3));
  Vector res = Vector::add_vector(v1, v2);
  cout << "(" << res.get_A().get_x() << ", " << res.get_A().get_y() << "),\n" << 
        "(" << res.get_B().get_x() << ", " << res.get_B().get_y() << ")\n";

}

