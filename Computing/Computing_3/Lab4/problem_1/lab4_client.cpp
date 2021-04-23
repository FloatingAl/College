#include <iostream>
#include "lab4.h"
#include <typeinfo>
#include <cmath>

using namespace std;

int main()
{
	Shape *shape[6];
	
	Circle circle(10.6);
	Square square(5.0,6.0);
	Triangle triangle(4.0, 4.0);

	Sphere sphere(5.0);
	Cube cube(4.0,5.0,6.0);
	Tetrahedron tet(6.0);

	shape[0] = &circle;
	shape[1] = &square;
	shape[2] = &triangle;
	shape[3] = &sphere;
	shape[4] = &cube;
	shape[5] = &tet;

	for (int i = 0; i < 6; i++) {
		if (dynamic_cast<TwoDS*>(shape[i])) {
			// Two DS Stuffs
			if (dynamic_cast<Circle*>(shape[i])) {
				cout << "\n";
				cout << "Two Dimension: Circle" << endl;
				cout << "Area: ";
			
			} else if (dynamic_cast<Square*>(shape[i])) {
				cout << "\n";
				cout << "Two Dimension: Square" << endl;
				cout << "Area: ";
			} else {
				cout << "\n";
				cout << "Two Dimension: Triangle" << endl;
				cout << "Area: ";
				
			}
			// 
			cout << shape[i]->getArea() << endl;
		} else {
			// Three DS stuffs
			if(dynamic_cast<Sphere*>(shape[i])){
				cout << "\n";
				cout << "Three Dimension: Sphere " << endl;
				cout << "Area: ";
				
			}

			else if (dynamic_cast<Cube*>(shape[i])){
				cout << "\n";
				cout << "Three Dimension: Cube " << endl;
				cout << "Area: ";
				
			}
			else{
				cout << "\n";
				cout << "Three Dimension: Tetrahedron " << endl;
				cout << "Area: " ;
				
			}
			cout << shape[i]->getArea() << endl;
			cout << "Volume: ";
			cout << shape[i]->getVolume() << endl;

		}
		
	}

    return 0;
}
