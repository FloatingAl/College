#include <iostream>
#include <string>

using namespace std;

class Invoice
{
	private:
		string name;
		string info;
		int quant;
		double price;
	public:
	//default
	Invoice(){
		
	}		
		//constructor
	Invoice(string name_,string info_, int quant_,double price_)
	{
		name = name_;
		info = info_;
		quant = quant_;
		price = price_;
	}
		
	void setName(string mName);
	string getName();
	void setInfo(string mInfo);
	string getInfo();
	void setQuant(int mQuant);
	int getQuant();
	void setPrice(double mPrice);
	double getPrice();
	double getInvoiceAmount();

			
};
