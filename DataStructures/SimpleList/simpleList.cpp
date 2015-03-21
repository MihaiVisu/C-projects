#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("f.in");

struct Node { // creating the structure of the node of a list
	int inf;
	Node* next;
};
typedef Node* List; // creating the List

List l;

inline void Insert (List& l, List p, int x ) // inserting an element into a list
{
	List q = new Node;
	q->inf = x;
	if(p==NULL)
	{
		q->next = l;
		l=q;
	}
	else
	{
		p->next = q;
	}
}

inline void Delete (List& l, List p)
{
	List q;
	if(p==NULL)
	{
		l=l->next;
	}
	else
	{
		q=p->next;
		p->next=q->next;
		delete q;
	}
}

inline void Write (List l)
{
	for(List p = l; p; p = p->next)
		cout<<p->inf<<' ';
	cout<<'\n';
}

int main()
{
	int n, x;
	fin >> n;
	for(int i = 1; i<= n; i++ )
	{
		fin>>x;
		Insert(l,NULL,x);
	}
	Write(l);
	fin.close();
	return 0;
}
