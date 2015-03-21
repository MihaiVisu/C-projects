#include <fstream>
using namespace std;

#define NUMBER 50001

int cst[NUMBER], n;

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


//graph structure
struct Graph 
{
	int node, cost;
	Graph* next;
} *g[NUMBER];


//add edge from where to what with cost c
inline void add (int where, int what, int c)
{
	Graph *p = new Graph;
	p->node = what;
	p->cost = c;
	p->next = g[where];
	g[where] = p;
}

void Dijkstra(int x)
{
	for(int i = 1; i<= n; i++ )
		cst[i]=999999999;
	cst[x]=0;
	queue<int>q;
	q.push(x);
	while(!q.empty())
	{
		x = q.front();
		q.pop();
		for(Graph *y = g[x]; y != NULL; y = y->next)
		{
			int newCost = cst[x]+y->cost;
			if(cst[y->node] > newCost)
			{
				cst[y->node] = newCost;
				q.push(y->node);
			}
		}

	}
}

int main ()
{
	ifstream fin("dijkstra.in");
	ofstream fout("dijkstra.out");
	int m, x, y, c;
	fin>>n>>m;
	for(int i = 1; i<= m; i++ )
	{
		fin>>x>>y>>c;
		add(x,y,c);
	}
	Dijkstra(1);
	for(int i = 2; i<= n; i++ )
		if(cst[i]!=999999999)
			fout<<cst[i]<<' ';
		else fout << "0 ";
	fin.close();
	fout.close();
	return 0;
}
