//Implementation of a doubly linked list.

class list
{
	private:
		typedef struct node
		{
			int num;
			char word;
			
			node* next;
			node* prev;
		}* nodeptr;

		//Sets key node pointers.
		nodeptr head;
		nodeptr tail;
		nodeptr curr;
		nodeptr temp;

		//Recursive functions:
		//Deletes list.
		void dellist(nodeptr & head);

		//Reads list forwards and backwards.
		void forreadlist(nodeptr & curr);
		void backreadlist(nodeptr & curr);
		
                //Sets current node to head;
                void setnodehead(nodeptr & curr);
		void setnodetail(nodeptr & curr);

	public:
		//Initialises list.
		list();

		//Adds nodes to front and end of a list.
		void addnodehead(int ahnum, char ahword);
		void addnodetail(int atnum, char atword);

		//Deletes nodes from the front and end of a list.
		void delnodehead();
		void delnodetail();

		//Recursive functions.
		void dellist(){dellist(head);};
		void forreadlist(){forreadlist(curr);};
		void backreadlist(){backreadlist(curr);};

		void setnodehead(){setnodehead(curr);};
		void setnodetail(){setnodetail(curr);};
};
