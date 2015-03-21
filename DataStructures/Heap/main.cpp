#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("f.in");
ofstream fout("f.out");

typedef int* Heap;
Heap h;

void CombHeap(int i, int n)
{
	int v=h[i];
	int father = i;
	int son=2*i;
	while(son<=n)
	{
		if(son<n)
			if(h[son]<h[son+1])
				son++;
		if(v<h[son])
		{
			h[father] = h[son];
			father = son;
			son *= 2;
		}
		else son = n+1;
	}
	h[father] = v;
}

void HeapSort(Heap h, int n)
{
	for(int i = n; i>1; i--)
	{
		int aux = h[1];
		h[1]=h[i];
		h[i]=aux;
		CombHeap(1,i-1);
	}
}

int main()
{
	int n, val;
	fin >> n;
	h = new int[n+1];
	for(int i=1; i<= n; i++)
		fin>>h[i];
	for(int i = n/2; i; i--)
		CombHeap(i,n);
	HeapSort(h,n);
	for(int i = 1; i<= n; i++ )
		fout << h[i] << ' ';
	fin.close();
	fout.close();
	return 0;
}

