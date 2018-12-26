#ifndef H_customerListType
#define H_customerListType

#include <iostream>
#include "binarySearchTree.h"
#include "customer.h"
 
using namespace std;

class customerBTreeType:public bSearchTreeType<customerType>
{
public:
	bool custSearchId(int id);
	void custReturnVideo(int id, string title);
	void custRentVideo(int id, string title);
	int  custGetNoOfRentals(int id);

	void rentedVideosInfo();

private:
	void searchCust(int id, bool& found,
					binaryTreeNode<customerType>* &current);

	void inorderRentedVideoInfo(binaryTreeNode<customerType>* p);
	// Function to do an inorder traversal and print
	// rented video information

};

#endif