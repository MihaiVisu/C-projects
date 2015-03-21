#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("f.in");

template <typename T>
class stack
{

private:
	struct Node
	{
		T item;
		Node *prev;

		Node (T newItem)
		{
			item = newItem;
			prev = NULL;
		}
	};

	Node *last;

public:

	//empty constructor
	stack()
	{
		last = NULL;
	}

	//push element to stack
	void push(T newItem)
	{
		Node *node = new Node(newItem);
		node ->prev = last;
		last = node;
	}

	//popping element from stack
	void pop()
	{
		if(last == NULL)
			return;
		Node *node = last->prev;
		delete last;
		last = node;
	}

	//get top element from stack
	T top()
	{
		return last->item;
	}

	//check if stack is empty
	bool empty()
	{
		return last == NULL;
	}
};

//checking my brand new stack class in the main function
int main()
{

	int n, x;
	stack<int>s;
	fin>>n;
	for(int i = 1; i<= n; i++ )
	{
		fin>>x;
		s.push(x);
	}
	cout<<s.top()<<'\n';
	s.pop();
	cout<<s.top()<<'\n';
	fin.close();
	return 0;
}

