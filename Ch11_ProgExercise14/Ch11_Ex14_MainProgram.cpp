#include <iostream>
#include <fstream>
#include "videoType.h"
#include "videoBinaryTree.h"
#include "customer.h"
#include "customerBinaryTree.h"
 
using namespace std;
 
void createVideoList(ifstream& infile, 
					 videoBinaryTree& videoList);
void createCustomerList(ifstream& infile,
				        customerBTreeType& custList);
void displayMenu();

int main()
{
	videoBinaryTree  videoList;
	ifstream infile, infile1;

	int choice;
	char ch;
	string title;
	int id;
	
	customerBTreeType custList;

	infile.open("videoDat.txt");
	if (!infile)
	{
		cout << "Input file does not exist" << endl;
		return 1;
	}

	createVideoList(infile, videoList);
	infile.close();

	infile1.open("custDat.txt");
	if (!infile1)
	{
		cout << "Input file does not exist" << endl;
		return 1;
	}

	createCustomerList(infile1,custList);
	infile1.close();

	displayMenu();
	cout << "Enter choice: ";
	cin >> choice;
    cin.get(ch);
	cout << endl;

	while (choice != 9)
	{
		switch (choice)
		{
		case 1: 
            cout << "Enter Title: ";
			getline(cin, title);
			cout << endl;
			if (videoList.videoSearch(title))
				cout << "Title found" << endl;
			else
				cout << "Video not in store" << endl;
			break;
		case 2: 
            cout << "Enter Title: ";
   			getline(cin, title);
			cout << endl;
			if (videoList.videoSearch(title))
			{
				if (videoList.isVideoAvailable(title))
				{
					cout << "Enter customer id: ";
					cin >> id;
					cout << endl;
					if (custList.custSearchId(id))
					{
						videoList.videoCheckOut(title);
						custList.custRentVideo(id, title);
						cout << "Enjoy your movie: " << title << endl;
					}
					else
						cout << "Not a customer" << endl;
				}
				else
					cout << "Currently " << title << " is out of stock." << endl;
			}
			else
				cout << "Video not in store" << endl;
			break;
		case 3: 
            cout << "Enter title: ";
			getline(cin, title);
			cout << endl;
			if (videoList.videoSearch(title))
			{
				cout << "Enter customer id: ";
				cin >> id;
				cout << endl;
				if (custList.custSearchId(id))
				{
					videoList.videoCheckIn(title);
					custList.custReturnVideo(id, title);
					cout << "Thanks for returning "
						 << title << endl;
				}
				else
					cout << "Not a customer" << endl;
			}
			else
				cout << "This video is not from our store" << endl;

			break;
		case 4: 
            cout << "Enter title: ";
			getline(cin, title);
			cout << endl;
			if (videoList.videoSearch(title))
			{
				if (videoList.isVideoAvailable(title))
					cout << "Currently in stock" << endl;
				else
					cout << "Out of stock" << endl;
			}
			else
				cout << "Video not in store " << endl;
			break;
		case 5: 
            videoList.videoPrintTitle();
			break;
		case 6: 
            videoList.inorderTraversal();
			break;
		case 7: 
            cout << " ";
			custList.inorderTraversal();
			break;
		case 8: 
            custList.rentedVideosInfo();;
			break;
		default: 
            cout << "Invalid selection." << endl;
		}

		displayMenu();
		cout << "Enter choice: ";
		cin >> choice;
        cin.get(ch);
		cout << endl;
	}//end while

	return 0;
}

void createVideoList(ifstream& infile, videoBinaryTree& videoList)
{
	string  title;
	string  star1;
	string  star2;
	string  producer;
	string  director;
	string  productionCo;
	char ch;
	int inStock;

	videoType newVideo;

	getline(infile, title);
	
	while (infile)
	{	
		getline(infile, star1);
        getline(infile, star2);
        getline(infile, producer);
        getline(infile, director);
        getline(infile, productionCo);
        infile >> inStock;
        infile.get(ch);
		newVideo.setVideoInfo(title,star1,star2,producer,
			                   director,productionCo,inStock);
		videoList.insert(newVideo);
		
		getline(infile, title);
	}//end while
}//end createVideoList

void displayMenu()
{
	cout << "Selec one of the following " << endl;
	cout << "1: To check if a particular video is in Store" << endl;
	cout << "2: To check out a video" << endl;
	cout << "3: To check in a video" << endl;
	cout << "4: To see if a particular video in stock" << endl;
	cout << "5: To print Titles of all videos" << endl;
    cout << "6: To print a list of all videos" << endl;
	cout << "7: Print a list of customers" << endl;
	cout << "8: Print a list showing which customer has rented which video" << endl;
	cout << "9: To exit" << endl;

}

void createCustomerList(ifstream& infile,
				        customerBTreeType& custList)
{
	string fname;
	string lname;
	int id;

	customerType cust;

	infile >> fname >> lname >> id;
	while (infile)
	{
		cust.setCustInfo(fname, lname, id);
		custList.insert(cust);
		infile >> fname >> lname >> id;
	}
}
