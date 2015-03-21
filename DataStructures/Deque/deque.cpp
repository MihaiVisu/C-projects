#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("f.in");
ofstream fout("f.out");


//my deque class

template <typename T>
class deque {

private:
	struct Node {
		T item;
		Node *prev, *next;

		Node (T newItem) {
			prev = next = NULL;
			item = newItem;
		}
	};
	Node *first, *last;


public:
	deque() {
		first=last=NULL;
	}

	//pushing element in front of deque
	void push_front(T newItem) {
		Node *node = new Node(newItem);
		if (first == NULL) {
			first = last = node;
		}
		else {
			first -> prev = node;
			node -> next = first;
			first = node;
		}
	}

	//popping element in front of deque
	void pop_front() {
		if (first == NULL) return;

		if(first->next == NULL)
			first = last = NULL;
		else {
			first = first->next;
			delete first->prev;
			first->prev = NULL;
		}
	}

	//pushing element at the back of deque
	void push_back(T newItem) {
		Node *node = new Node(newItem);

		if ( last == NULL) {
			first = last = node;
		}
		else {
			last->next = node;
			node->prev = last;
			last = node;
		}
	}

	//popping element from the back of deque
	void pop_back() {
		if ( last == NULL) return;

		if( last->prev == NULL)
			first = last = NULL;
		else {
			last = last->prev;
			delete last->next;
			last->next = NULL;
		}
	}

	//getters-----

	//get pointer to the first element in deque
	Node *begin() {
		return first;
	}

	//get pointer to the last element in deque
	Node *end() {
		return last;
	}

	//get value of first element in deque
	T front() {
		return first -> item;
	}

	//get value of last element in deque
	T back() {
		return last->item;
	}

	//------------
	
	//check if deque is empty
	bool empty() {
		return (first==NULL);
	}

};
//testing my brand-new deque in the main function
int main()
{
	int n, val;

	deque<int> dq;

	fin >> n;
	for(int i = 1; i<= n; i++ )
	{
		fin >> val;
		dq.push_front(val);
	}

	cout << dq.front() << ' ' << dq.back() << '\n';
}
