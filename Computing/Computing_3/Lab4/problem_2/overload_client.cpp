/* Name; Albara Mehene
   Date: 3/30/15
   Computing III*/
#include <iostream>
#include <cmath>
#include "overload.h"

int main(){

	double a[3] = {7.5, 5.5, 3.5};
	double b[4] = {18.9,6.7, 4.4, 8.9};
	double c[5] = {21.0,15.5,-12.0,30.0, 50.2};
	Polynomial object1(a,3);
	Polynomial object2(b,4);
	Polynomial object3(c,5);

	double	ask;
	cout << "What is the value for x: ";
	cin >> ask;

 	object1.print();
 	cout << " The equation after plugging in x:" << object1.getAnswer(ask) << endl;
 	object2.print();
 	cout << " The equation after plugging in x:" << object2.getAnswer(ask) << endl;
 	object3.print();
 	cout << " The equation after plugging in x:" << object3.getAnswer(ask) << endl;

 	cout << "\n" << endl;

 	//print out overload for addition
	Polynomial temp = (object1 + object3);	
	cout << " The equation after adding in x:" << temp.getAnswer(ask) << endl;

	//print out overload for subtraction
	temp = (object2 - object1);
	cout << " The equation after subtracting in x:" << temp.getAnswer(ask) << endl;

	//print out overload for multiply
	temp = (object1 * object2);
	cout << " The equation after multiplying in x:" << temp.getAnswer(ask) << endl;



 }