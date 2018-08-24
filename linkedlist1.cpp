////Main file for linear linked list exercise. Program will create a list of integers, to which more nodes are added in sorted order. A destructor program is also written, which will delete the entire list node by node. Also a read out function to output every integer stored.

#include <cstdlib>
#include <iostream>

#include "linkedlist1.h"

using namespace std;

list::list() //Initialises the list. 
{
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void list::addnode (int adddata) //function to add a node to the end of the list.
{
	nodeptr n = new node; //n now creates a new node.
	n -> next = NULL;
	n -> data = adddata;

	if ( head != NULL)
	{
		curr = head;
		while ( curr -> next != NULL) //Finds the last node.
		{
			curr = curr -> next;
		}
		curr -> next = n; //Adds the new node.
	}
	else //If the list is empty, the new node is the head.
	{
		head = n;
	}

}

void list::delnode (int deldata) //Function to remove a specific element of data.
{
	nodeptr delptr = NULL;
	temp = head;
	curr = head;
	
	while ( curr != NULL && curr -> data != deldata)
	{
		temp = curr; //This line and the next keeps the temp and curr apart by one. Thus allowing the previous and next to be linked together.
		curr = curr -> next;
	}
	
	if (curr == NULL) //Value was not found in the list.
	{
		cout << deldata << "was not in the list" << endl;
		delete delptr;
	}
	
	else
	{
		delptr = curr; //Node marked for deletion.
		curr = curr -> next; //Marks the next node for linking.
		temp -> next = curr; //Links the node before the to-be-deleted node to the node after.
		delete delptr; //deletes node.
		cout << "The value " << deldata << " was deleted." << endl;
	}
}

void list::readlist ()
{
	curr = head;
	while (curr !=  NULL) //As long as it is pointing to an element in the list.
	{
		cout << curr -> data << " "; //prints out the data in the node.
		curr = curr -> next;
	}
	cout << endl;
}

//User input based functions.

void list::uaddnode (int uadddata) //function for the user to add a node to the end.
{

	cout << "Please type in the integer you want stored on the new node: ";
	cin >> uadddata;
	cout << endl;
	
        nodeptr n = new node; //n now creates a new node.
        n -> next = NULL;
        n -> data = uadddata;

        if ( head != NULL)
        {
                curr = head;
                while ( curr -> next != NULL) //Finds the last node.
                {
                        curr = curr -> next;
                }
                curr -> next = n; //Adds the new node.
        }
        else //If the list is empty, the new node is the head.
        {
                head = n;
        }

}

void list::udelnode (int udeldata) //Function to remove a specific element of data.
{
        nodeptr delptr = NULL;
        temp = head;
        curr = head;

        cout << "Please type in the integer you want deleted from the list: ";
        cin >> udeldata;
        cout << endl;
	
	if (curr == head && curr -> data == udeldata )
	{
		delptr = curr;
		head = curr -> next;
		curr = head;
		temp = head;
		delete delptr;
	}
	
	else
	{
		while ( curr != NULL && curr -> data != udeldata)
	       	{
       	        	temp = curr; //This line and the next keeps the temp and curr apart by one. Thus allowing the previous and next to be linked together.
       	        	curr = curr -> next;
       		}
	
       	 if (curr == NULL) //Value was not found in the list.
       		{
			cout << udeldata << "  Was not in the list" << endl;
       		        delete delptr;
       		}
		
       	else
	        {
       		        delptr = curr; //Node marked for deletion.
	                curr = curr -> next; //Marks the next node for linking.
	       	        temp -> next = curr; //Links the node before the to-be-deleted node to the node after.
	               	delete delptr; //deletes node.
		cout << "The value " << udeldata << " was deleted." << endl;
	}
}
}

void list::faddnode(int fadddata)//To add a node to the front of the list.
{

	cout << "Please type in the integer you want stored on the new node: ";
	cin >> fadddata; //Accepts the data from the user.
	cout << endl;

	nodeptr n = new node; //n now creates a new node.
	temp = head; //marks the present head.
	curr = n; //marks the new node.
	head = n; //Marks the new node as the head.
	n -> next = temp; //Links the new node to the list, by assigning the old head as the next node.
	n -> data = fadddata; //Assigns the data to said node.

}

void list::saddnode(int sadddata) //Sorts the new entries such that the list of integers will count down.
{
	cout << "Please type the integer you want stored on the new node: ";
	cin >> sadddata; //Accepts the data from the user.
	cout << endl;

	nodeptr n = new node; //n creates a new node.

	temp = head;
	curr = head;

	n -> data = sadddata;

	if (head == NULL) //For an empty list.
	{
		head = n;
		curr = head;
		temp = head;
	}

	else if (curr -> next != NULL) //If the new node will be in the middle of the list.
	{

		while ( curr -> data != sadddata && curr -> next != NULL) //While the current term is not equal to the input integer.
		{
			if (curr -> data > sadddata) //Input integer is larger than the current node.
			{
				temp = curr;
				curr = curr -> next;
			}

			else if (curr -> data <= sadddata) //Input integer is smaller or equal to the current node.
			{
				temp -> next = n;
				n -> next = curr;
			}
		}

	}	
	
	else if (curr -> next == NULL)//End of a list
	{
		curr -> next = n;
		n -> next = NULL;
	}
}

void list::dellist(nodeptr &head)
{


	if (!head)
	{
		cout << "List is empty" << endl;
		return;
	}
	dellist(head -> next);
	head = NULL;
	delete head;
//	cout << "The list is empty." << endl;

}




int main()
{
        list intlist;

	int x;
	int y;
	int z;

	cout << "Please enter two numbers to add to the list. These will be added to the front, sequentially. The following two elements of the list will be 3 and 4. " << endl;
	
	intlist.faddnode(x);
	intlist.faddnode(y);

        intlist.addnode(3);
	intlist.addnode(4);
//        intlist.addnode(5);
//        intlist.addnode(7);
//  	intlist.uaddnode(x);

//	cout << endl;

        intlist.readlist();

//	cout << endl;

	intlist.udelnode(z);

//	cout << endl;
	
	intlist.readlist();

	int a;
	int b;

	cout << "Now you will enter two numbes to be added to the end of the list sequentially." << endl;

	intlist.uaddnode(a);
	intlist.uaddnode(b);

	intlist.readlist();
	
	cout << endl;

	intlist.dellist();

	cout << endl;

	int c;
	int d;
	int e;

	intlist.saddnode(c);

	intlist.readlist();

	intlist.saddnode(d);

	intlist.readlist();	

	intlist.saddnode(e);

	intlist.readlist();


       
 return 0;
}
