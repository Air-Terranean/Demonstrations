//Header file for linear linked list exercise. Program will create a list of integers, to which more nodes are added in sorted order. A destructor program is also written, which will delete the entire list node by node. Also a read out function to output every integer stored.

class list
{
	private: //Structure. typedef enables quick assignment of nodes.
		typedef struct node
		{
			int data;
			node* next;
		}* nodeptr;

		nodeptr head;
		nodeptr curr;
		nodeptr temp;

		void dellist(nodeptr & head);

	public: //Functions.
		list (); 
		void addnode (int adddata);
		void delnode (int deldata);
		void readlist();

		//Functions where the user adds/deletes a node.

                void uaddnode (int uadddata);
                void udelnode (int udeldata);

		//Functions where the user states how many nodes they want to add/delete.

		void addnum (int uaddnum);
		void delnum (int udelnum);
		
		//Function to add a node in front of the (now) head.

		void faddnode (int fadddata);

		//Function to add a node in sorted order.

		void saddnode (int sadddata);

		//Function to erase the entire list.

		void dellist(){dellist(head);};

};
