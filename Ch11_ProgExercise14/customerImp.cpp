#include <iostream>
#include "customer.h"

using namespace std;
 
void customerType::print()
{
	cout << custAcctNo << " ";
	personType::print();
	cout << " " << rentedVideoTree.treeNodeCount() << endl;
}

void customerType::setCustInfo(string first, string last,
							   int acctNo)
{
	personType::setName(first,last);
	custAcctNo = acctNo;
}
 
void customerType::rentVideo(string title)
{
	rentedVideoTree.insert(title);
}
void customerType::returnVideo(string title)
{
	rentedVideoTree.deleteNode(title);
}

int customerType::getNoOfRentals() const
{
	return rentedVideoTree.treeNodeCount();
}

int customerType::getAcctNo()
{
	return custAcctNo; 
}

customerType::customerType(string first, string last, 
						   int acctNo)
				:personType(first,last)
{
	custAcctNo = acctNo;
}

customerType::customerType()
{
	custAcctNo = 0;
}


bool customerType::operator==(const customerType& right) const
{
	return (custAcctNo == right.custAcctNo);
}

bool customerType::operator!=(const customerType& right) const
{
	return (custAcctNo != right.custAcctNo);
}

bool customerType::operator<=(const customerType& right) const
{
	return (custAcctNo <= right.custAcctNo);
}

bool customerType::operator<(const customerType& right) const
{
	return (custAcctNo < right.custAcctNo);
}

bool customerType::operator>=(const customerType& right) const
{
	return (custAcctNo >= right.custAcctNo);
}

bool customerType::operator>(const customerType& right) const
{
	return (custAcctNo > right.custAcctNo);
}

ostream& operator << (ostream& os, const customerType& cust)
{
	string fname = cust.getFirstName();
	string lname = cust.getLastName();

	os << cust.custAcctNo << " " << fname
	   << " " << lname
	   << " " << cust.rentedVideoTree.treeNodeCount() << endl;

	return os;
}

void customerType::printRentedVideo()
{ 
	rentedVideoTree.inorderTraversal();
}