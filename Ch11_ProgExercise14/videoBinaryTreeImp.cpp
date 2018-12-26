#include <iostream>
#include <string>
#include "videoBinaryTree.h"

using namespace std;
 
bool videoBinaryTree::isVideoAvailable(string title) 
{
    bool found;
    binaryTreeNode<videoType> *location;

    searchVideoList(title,found,location);

    if (found)
        found = (location->info.getNoOfCopiesInStock() > 0);
    else 
        found = false;

    return found;
}

void videoBinaryTree::videoCheckIn(string title)
{
	bool found = false;
	binaryTreeNode<videoType> *location;

	searchVideoList(title,found,location);

	if (found)
		location->info.checkIn();
	else
		cout<<"The video is not in stock."<<endl;
}

void videoBinaryTree::videoCheckOut(string title)
{
    bool found = false;
    binaryTreeNode<videoType> *location;

    searchVideoList(title,found,location);

    if (found)
        location->info.checkOut();
    else
        cout << "The video is not in stock." << endl;
}

bool videoBinaryTree::videoCheckTitle(string title)
{
    bool found = false;
    binaryTreeNode<videoType> *location;

    searchVideoList(title,found,location);

    return found;
}

void videoBinaryTree::videoUpdateInStock(string title, int num)
{
    bool found = false;
    binaryTreeNode<videoType> *location;

    searchVideoList(title,found,location);

    if (found)
        location->info.updateInStock(num);
    else
        cout << "The video is not in stock." << endl;
}

void videoBinaryTree::videoSetCopiesInStock(string title, 
											int num)
{
    bool found = false;
    binaryTreeNode<videoType> *location;

    searchVideoList(title, found, location);

    if (found)
        location->info.setCopiesInStock(num);
    else
        cout << "The video is not in stock." << endl;
}

bool videoBinaryTree::videoSearch(string title)
{
    bool found = false;
    binaryTreeNode<videoType> *location;

    searchVideoList(title, found, location);

    return found;
}

void videoBinaryTree::searchVideoList(string title, bool& found,
                                   binaryTreeNode<videoType>* &current)
{
    found = false;   
   
    videoType temp;

    temp.setVideoInfo(title, "", "", "", "", "", 0);

    if (root == NULL)  //the tree is empty
        cout << "Cannot search an empty list. " << endl;
    else
    {
        current = root; //set current point to the root node 
                        //of the binary tree
        found = false;  //set found to false

        while (!found && current != NULL) //search the tree
            if (current->info == temp)    //the item is found
                found = true;
            else if(current->info > temp)
                current = current->llink;
            else
                current = current->rlink;
    } //end else
}

void videoBinaryTree::videoPrintTitle()
{
	inorderTitle(root);
}

void videoBinaryTree::inorderTitle(binaryTreeNode<videoType> *p)
{
    if (p != NULL)
    {
        inorderTitle(p->llink);
        p->info.printTitle();
        inorderTitle(p->rlink);
    }
}

