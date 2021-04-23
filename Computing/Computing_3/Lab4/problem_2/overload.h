
#include <iostream>
#include <cmath>

using namespace std;

class Polynomial{
private:
	double *coefficient_;
	int exponent_;
	double result_;
public:
	Polynomial(){

	}

	Polynomial(double *coefficient, int exponent)
	{
		coefficient_ = new double[exponent + 1];
		exponent_ = exponent;
		for(int i = 0; i <= exponent_; i++){
			coefficient_[i] = coefficient[exponent_ - i];
		}
	}
	double getAnswer(double answer);
	void print();

	Polynomial operator+(Polynomial &arg);
    Polynomial operator-(Polynomial &arg);
    Polynomial operator*(Polynomial &arg);


};
