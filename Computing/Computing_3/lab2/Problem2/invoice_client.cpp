#include <iostream>
#include <string>
#include "Invoice.h"

int main()
{	
	Invoice item1;
	Invoice item2;
	
	item1.setName("Nails");
	item1.setInfo("Top notch nails used by professionals");
	item1.setQuant(50);
	item1.setPrice(2.99);
	
	item2.setName("Hammers");
	item2.setInfo("Hammers with state of the art handeling and better grip");
	item2.setQuant(8);
	item2.setPrice(19.99);
	

	cout << "Name:" << item1.getName() << endl;
	cout << "Description:" << item1.getInfo() << endl;
	cout << "Quantity:" << item1.getQuant() << endl;
	cout << "Price:$" << item1.getPrice() << endl;	
	cout << "\n";	
	cout << "The Invoice of " << item1.getName() << " is:" << item1.getInvoiceAmount() << endl;
	
	cout << "Name:" << item2.getName() << endl;
	cout << "Description:" << item2.getInfo() << endl;
	cout << "Quantity:" << item2.getQuant() << endl;
	cout << "Price:$" << item2.getPrice() << endl;

	cout << "\n";	
	cout << "The Invoice of " << item2.getName() << " is:" << item2.getInvoiceAmount() << endl;
     
	
	

	return 0;
}
