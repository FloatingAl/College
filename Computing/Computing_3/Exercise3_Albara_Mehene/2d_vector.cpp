/*
	Name: Albara Mehene
	2/17/2016
	Computing 3 COMP 2010
*/

#include <iostream>

using namespace std;

class Vector
{
  private:
	double x;
	double y;
  public:
	//Default Constucture
	Vector(){
	}
	//Construture	
	Vector(double x_, double y_)
	{
		x = x_;
		y = y_;
	}
	
	void add_vector(Vector temp);
	void sub_vector(Vector temp);
	
	void set_x(double mX);
	double get_x();
	void set_y(double mY);
	double get_y();
	

};

int main()
{	//created 2 vectors
	Vector vector1;
	Vector vector2;

	vector1.set_x(5.5);
	vector1.set_y(9.2);
	vector2.set_x(12.2);
	vector2.set_y(20.8);
	
	// I gave vector 1, vector 2 so it can have access to the values
	vector1.add_vector(vector2);
	vector1.sub_vector(vector2);
	
}
//The set and get is used to get th vaule stored in the private
void Vector::set_x(double mX)
{
	x = mX;
}
double Vector::get_x()
{
	return x;
}
void Vector::set_y(double mY)
{
	y = mY;
}	
double Vector::get_y()
{
	return y;
}
	
//Function takes a vector, I passing it the second vector and then just adding both x and y.
void Vector::add_vector(Vector temp)
{
	cout << "The addition of both vectors of x is: " << x + temp.get_x() << endl;
	
	cout << "The addition of both vectors of y is: " << y + temp.get_y() << endl;
}

//Same for this function
void Vector::sub_vector(Vector temp)
{
	cout << "The subtraction of both vectors of x is: " << x - temp.get_x() << endl;
	
	cout << "The subtraction of both vectors of y is: " << y - temp.get_y() << endl;
	
}
