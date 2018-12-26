#include <iostream>

#include "customerBinaryTree.h"

using namespace std;
 
bool customerBTreeType::custSearchId(int id)
{
	bool found;
	binaryTreeNode<customerType> *current;

	searchCust(id, found, current);
	return found;

}

void customerBTreeType::custReturnVideo(int id, string title)
{
	bool found;
	binaryTreeNode<customerType> *current;

	searchCust(id, found, current);
	current->info.returnVideo(title);
}

void customerBTreeType::custRentVideo(int id, string title)
{
	bool found;
	binaryTreeNode<customerType> *current;

	searchCust(id, found, current);
	current->info.rentVideo(title);
}

int customerBTreeType::custGetNoOfRentals(int id)
{
	bool found;
	binaryTreeNode<customerType> *current;

	searchCust(id, found, current);

	return current->info.getNoOfRentals();
}


void customerBTreeType::searchCust(int id, bool& found,
						           binaryTreeNode<customerType>* &current)
{
	found = false;   //set found to false
   
	current = NULL;

   if (root == NULL)  // list is empty
      cout << "Cannot search an empty list. " << endl;
   else
   {
		current = root;  // set current point to root node of the tree
		found = false;       // set found to false

		while (!found && current != NULL) //search the tree
			if (current->info.getAcctNo() == id)   //item is found
       			found = true;
			else if(current->info.getAcctNo() > id)
				current = current->llink;
			else
				current = current->rlink;
	} //end else
}

void customerBTreeType::rentedVideosInfo()
{
	binaryTreeNode<customerType> *current;
	current = root;

	cout << "         ######## Rented Video Info ########"
		 << endl << endl;
	
	inorderRentedVideoInfo(root);
}

void customerBTreeType::inorderRentedVideoInfo(binaryTreeNode<customerType>* p)
{
	if (p != NULL)
	{
		inorderRentedVideoInfo(p->llink);
		if (p->info.getNoOfRentals() > 0)
		{
			cout << "Customer ID: " << p->info.getAcctNo()
				 << endl;
			cout << "Videos Rented: ";
			p->info.printRentedVideo();
			cout << "*****************" << endl << endl;
		}
		inorderRentedVideoInfo(p->rlink);
	}
}