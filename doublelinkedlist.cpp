#include <cstdlib>
#include <iostream>
#include <string>

#include "doublelinkedlist.h"

using namespace std;

list::list()
{
	head = NULL;
	tail = NULL;
	temp = NULL;
	curr = NULL;
}

void list :: addnodehead (int ahnum, char ahword)
{
	cout << "Enter a number: " << endl;
	cin >> ahnum;
	cout << endl;
	cout << "Enter a word: " << endl;
	cin >> ahword;	

	nodeptr n = new node;
	n -> prev = NULL;
	n -> num = ahnum;
	n -> word = ahword;

	if (head == NULL)
	{
		n -> next = NULL;
		tail = n;
		head = n;
	}

	else
	{
		temp = head;
		n -> next = temp;
		temp -> prev = n;
		head = n;
	}
}

void list :: addnodetail (int atnum, char atword)
{
        cout << "Enter a number: " << endl;
        cin >> atnum;
        cout << endl;
        cout << "Enter a word: " << endl;
        cin >> atword;

        nodeptr n = new node;
        n -> next = NULL;
        n -> num = atnum;
        n -> word = atword;

        if (tail == NULL)
        {
                n -> prev = NULL;
                tail = n;
                head = n;
        }

        else 
        {
                temp = tail;
                n -> prev = temp;
		temp -> next = n;
                tail = n;
        }
}

void list :: delnodehead()
{
	temp = head;
	head = head -> next;
	head -> prev = NULL;
	delete temp;

	curr = head;
	temp = head;
}

void list :: delnodetail()
{
	temp = tail;
	tail = tail -> prev;
	tail -> next = NULL;
	delete temp;

	curr = tail;
	temp = tail;
}

void list :: forreadlist(nodeptr & curr)
{
	
	if (curr != NULL)
	{
	        cout << curr -> num << " " << curr -> word << endl;
		forreadlist(curr -> next);
	}
	else
	{
	cout << "End of list"  << endl;
	}
}

void list :: backreadlist(nodeptr & curr)
{
        
      
        if (curr != NULL)
        {
	        cout << curr -> num << " " << curr -> word << endl;
                backreadlist(curr -> prev);
        }
        else
        {
        cout << endl;
        }
}

void list :: dellist(nodeptr & head)
{
	if(!head)
	{
		temp = NULL;
		curr = NULL;
		cout << "The list is empty." << endl;
	}
	else
	{
		dellist(head -> next);
		head = NULL;
		delete head;
	}
}

void list :: setnodehead(nodeptr & curr)
{
	curr = head;
}

void list :: setnodetail(nodeptr & curr)
{
	curr = tail;
}

int main()
{
	list doublelist;
	
	int a;
	int b;
	int c;	
	int d;
	char aa;
	char ab;
	char ac;
	char ad;


	doublelist.addnodehead(a,aa);
	doublelist.addnodehead(b,ab);
	doublelist.addnodetail(c,ac);
	doublelist.addnodetail(d,ad);

	cout << endl;

	doublelist.setnodehead();

	doublelist.forreadlist();

	doublelist.setnodetail();	

	doublelist.backreadlist();

	doublelist.dellist();

return 0;
}
