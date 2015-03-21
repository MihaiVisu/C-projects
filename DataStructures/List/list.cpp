#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("f.in");

template <typename T>
class List
{
	private:
		struct Node
		{
			T item;
			Node *next, *prev;

			Node(T newItem)
			{
				item=newItem;
				next = NULL;
				prev = NULL;
			}
		};

		Node *first, *last;

	public:
		List()
		{
			first=last=NULL;
		}

		//inserting element in list
		void push_back(T newItem)
		{
			Node* p = new Node(newItem);
			if(first==NULL)
			{
				first = last = p;
				return;
			}
			last->next = p;
			p->prev = last;
			last = p;
		}

		//erasing element in list
		void pop_back()
		{
			if(first==NULL)
				return;
			if(first == last)
			{
				first = last = NULL;
			}
			Node *p = last->prev;
			delete last;
			last = p;
		}

		//access first element of list
		T front()
		{
			return first->item;
		}

		//access last element of list
		T back()
		{
			return last->item;
		}

		//return iterator to first element
		Node * begin()
		{
			return first;
		}

		//return iterator to last element
		Node * end()
		{
			return last;
		}

		//searches for element in list
		bool find(T findItem)
		{
			for(Node* p = first; p != last; p = p->next)
			{
				if (p->item == findItem)
					return true;
			}
			return false;
		}

		//checks if list is empty
		bool empty()
		{
			return first==NULL;
		}

};

//checking my brand new list class
int main()
{
	int n, x;
	List<int>l;
	fin>>n;
	for(int i = 1; i<= n; i++ )
	{
		fin >> x;
		l.push_back(x);
	}

	cout << l.front()<<'\n'<<l.back()<<'\n';
	l.pop_back();
	cout<<l.back()<<'\n';

	fin.close();
	return 0;
}

