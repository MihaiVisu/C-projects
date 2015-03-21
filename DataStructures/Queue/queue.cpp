#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("f.in");

template <typename T>
class queue
{

private:
	struct Node
	{
		T item;
		Node *next;

		Node(T newItem)
		{
			next = NULL;
			item = newItem;
		}
	};

	Node *first, *last;

public:

	//empty constructor
	queue()
	{
		first=last=NULL;
	}

	//pushing element in the queue
	void push (T newItem)
	{
		Node *node = new Node(newItem);
		if(first==NULL)
			first = last = node;
		else
		{
			last->next = node;
			last = node;
		}
	}

	//popping element from the queue
	void pop()
	{
		if(first==NULL)
			return;
		Node *node=first;
		if(first->next==NULL)
			first=last=NULL;
		else
			first=first->next;
		delete node;
	}

	//getting first element from queue
	T front()
	{
		return first->item;
	}

	//getting last element from queue
	T end()
	{
		return last->item;
	}

	//check if queue is empty
	bool empty()
	{
		return last == NULL;
	}
};

//testing my brand new queue class in the main function;
int main()
{

	int n,x;
	queue<int>q;
	fin>>n;
	for(int i = 1; i<= n; i++ )
	{
		fin>>x;
		q.push(x);
	}
	cout << q.front() <<'\n';
	q.pop();
	cout << q.front() << ' '<<q.end()<<'\n';
	fin.close();
	return 0;
}

