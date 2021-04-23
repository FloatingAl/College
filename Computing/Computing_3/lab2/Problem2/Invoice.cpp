#include <iostream>
#include <string>
#include "Invoice.h"

// The getName is used to retireve what user wants to retrieve
string Invoice::getName()
{
	return name;
}
//The setName is used set up to retrieve what the name is and store it into mName
void Invoice::setName(string mName)
{
	name = mName;
}


string Invoice::getInfo()
{
	return info;
}
void Invoice::setInfo(string mInfo)
{
	info = mInfo;
}


int Invoice::getQuant()
{
	return quant;
}
void Invoice::setQuant(int mQuant)
{
	quant = mQuant;	
}


double Invoice::getPrice()
{
	return price;
}
void Invoice::setPrice(double mPrice)
{
	price = mPrice;
}

//Invoice have access to both quant and price because I passed the obeject of the first item.
double Invoice::getInvoiceAmount()
{
	if(quant < 0)
	{
		quant = 0;
	}
	if( price < 0 )
	{
		price = 0;
	}		
	
	return quant * price;

	
}

	


