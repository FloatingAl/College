
#include <iostream>
#include <cmath>
#include "overload.h"
 using namespace std;

//prints out end result of operator
double Polynomial::getAnswer(double answer){
	double result_ = 0;

	for(int i = 0; i <= exponent_; i++){
       result_ += coefficient_[i] * pow(answer, i);
	}
  
  	return result_;
}

//prints out he polynomial
void Polynomial::print(){

	for(int i = exponent_; i > 0; i--){
		cout << "(" << coefficient_[i] << ") * x^" << i << "+";
		cout << coefficient_[i] << endl;
	}
}

Polynomial Polynomial::operator+(Polynomial &arg)
{
	//set i to 0 and a to the exponent given
	int i = 0;
	int a = this->exponent_;
	//put in element
	if(this->exponent_ <= arg.exponent_){
    	double *array = new double[arg.exponent_];
    	Polynomial temp(array, arg.exponent_ );
    	//smaller coefficent
    		while(i <= this->exponent_){
     			temp.coefficient_[i] = this->coefficient_[i] + arg.coefficient_[i];
     			i++; 
    		}
    			//larger coeffient
    			while(a <= arg.exponent_){
      				temp.coefficient_[a] = arg.coefficient_[a];
      				a++;
    			}
    
    				return temp;

   }

}
Polynomial Polynomial:: operator-(Polynomial &arg)
{
	int i = 0;
	int a = this->exponent_;

	if(this->exponent_ <= arg.exponent_){
    	double *array = new double[arg.exponent_];
    	Polynomial temp(array, arg.exponent_ );

    		while(i <= this->exponent_){
     			temp.coefficient_ [i] = this->coefficient_[i] - arg.coefficient_[i];
     			i++; 
    		}

    			while(a <= arg.exponent_){
      				temp.coefficient_ [a] = arg.coefficient_[a];
      				a++;
    			}
    
    				return temp;
	

   		}
}

Polynomial Polynomial::operator*(Polynomial &arg){

	int i = 0;
	int a = this->exponent_;

	if(this->exponent_ <= arg.exponent_){
    	double *array = new double[arg.exponent_];
    	Polynomial temp(array, arg.exponent_ );

    		while(i <= this->exponent_){
     			temp.coefficient_[i] = this->coefficient_[i] * arg.coefficient_[i];
     			i++; 
    		}

    			while(a <= arg.exponent_){
      				temp.coefficient_[a] = arg.coefficient_[a];
      				a++;
    			}
    
    				return temp;
	

   		}
}


