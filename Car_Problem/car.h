#ifdef CAR_H
#define CAR_H

#include <iostream>
#include <string>


class Carwork
{	

public:
	bool wheels;
	double turn;
	int gas;

	Carwork();

	virtual bool run_wheel();
	virtual double turn_degree();
	virtual int check_gas();
	virtual int fill_gas();
};


class Car: public Carwork
{
public:
	std::string name;

	Car();
	Car(std::string);

};

#endif 

