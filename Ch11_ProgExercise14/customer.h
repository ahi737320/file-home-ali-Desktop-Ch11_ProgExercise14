
#ifndef H_customerType
#define H_customerType
 
#include <iostream>
#include "personType.h"
#include "binarySearchTree.h"

using namespace std;

class customerType: public personType
{
   friend ostream& operator << (ostream&, const customerType&);
	  // overload stream insertion operator
public:
	void print();
	  // Output account number, first name, last name, and 
	  // number of rentals, in the form:
	  // acctNo firstName lastName noOfRentals
	void setCustInfo(string first, string last, int acctNo);
	  // set firstName, lastName, account number, number of rentals according to the parameters
	  // firstName = first; lastName = last; 
	void rentVideo(string title);
	  // This function rents a video to the customer

	void returnVideo(string title);
	  // This function renturns a video to the customer

	int getNoOfRentals() const;
	  // This function returns the number of
	  // videos rented by the customer.
	int getAcctNo();
	  // This function returns the account number of
	  // the customer.
	customerType(string first, string last, int acctNo);
	  // constructor with parameters
	  // set firstName and lastName according to the parameters
	  // firstName = first; lastName = last;
  	customerType(); 
  	 // default constructor;
  	 // intialize firstName and lastName, custAcctNo, and noOfRentals 
  	 // Post condition: firstName = ""; lastName = "";
	 //					custAcctNo = 0; 

	void printRentedVideo();

		//overload operators for comparisons 
	bool operator==(const customerType&) const;
	bool operator!=(const customerType&) const;
	bool operator<=(const customerType&) const;
	bool operator<(const customerType&) const;
	bool operator>=(const customerType&) const;
	bool operator>(const customerType&) const;

private:
	int custAcctNo; // store account number
	bSearchTreeType<string> rentedVideoTree;
};

#endif 