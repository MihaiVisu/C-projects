#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;

ifstream fin("f.in");
ofstream fout("f.out");

int n, v[1001];

void QuickSort (int left, int right)
{
	if(left >= right) return;
	int i = left, j = right, di=0, dj=1;
	while (i < j)
	{
		if(v[i] > v[j])
		{
			swap (v[i],v[j]);
			di = 1-di;
			dj = 1-dj;
		}
		i += di;
		j -= dj;
	}
	
	QuickSort(left,j);
	QuickSort(j+1,right);

}

int main()
{
	fin>>n;
	for (int i = 1; i <= n; ++i)
	{
		fin>>v[i];
	}
	QuickSort(1,n);

	for (int i = 1; i < n+1; ++i)
	{
		fout << v[i] <<' ';
	}

	fin.close();
	fout.close();
	return 0;
}