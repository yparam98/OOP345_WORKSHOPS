//	program		:	Product.cpp
//	programmer	:	Yathavan, Parameshwaran
//	date		:	March 5, 2019
//	professor	:	Chris, Szalwinski

#include "Product.h"

extern int FW;

namespace sict
{
	Product::Product() {}

	//2 arg. constructor, initialized object w/ incoming params
	Product::Product(size_t incomingProductNum, double incomingPrice)
	{
		this->myProductNum = incomingProductNum;
		this->myPrice = incomingPrice;
	}

	//price query, returns price
	double Product::price() const
	{
		return this->myPrice;
	}

	//display query, prints product description to output
	void Product::display(std::ostream & os) const
	{
		int fieldWidth = FW;

		os << this->myProductNum
			<< std::setw(fieldWidth)
			<< this->myPrice
			<< " " << std::endl;
	}

	//readRecord, reads records from incoming file object
	iProduct* readRecord(std::ifstream& file)
	{
		std::string temp;
		size_t proNum;
		double priceVar;

		if (file.eof())
		{
			throw("end of file met...");
		}
		else
		{
			std::getline(file, temp, '\n');
			proNum = std::stoi(temp.substr(0, temp.find_first_of(' ')));
			priceVar = std::stod(temp.substr(temp.find_last_of(' '), temp.length()));

			return new Product(proNum, priceVar);
		}
		
		
	}

	//ostream overload, prints iProduct object to output
	std::ostream& operator<<(std::ostream & os, const iProduct & p)
	{
		p.display(os);
		return os;
	}
	// TaxableProduct::TaxableProduct(unsigned int incomingProNum, double incomingPrice, char incomingTaxType) : Product(incomingProNum, incomingPrice)
	// {
	// 	isTaxable = incomingTaxType;
	// }
	// double TaxableProduct::price() const
	// {
	// 	if (isTaxable == 'H')
	// 	{
	// 		double tempPrice = this->price();
	// 		double tax = (tempPrice / 100) * HST;
	// 		return tempPrice + tax;
	// 	}
	// 	else if (isTaxable == 'P')
	// 	{
	// 		double tempPrice = this->price();
	// 		double tax = (tempPrice / 100) * PST;
	// 		return tempPrice + tax;
	// 	}
	// }
	// void TaxableProduct::display(std::ostream & os) const
	// {
	// 	os << isTaxable;
	// }
}