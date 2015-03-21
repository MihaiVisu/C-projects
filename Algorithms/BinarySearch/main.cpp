#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
ifstream fin("f.in");
ofstream fout("f.out");

int n, a[1001], el;

inline int BinarySearch (int x, int left, int right)
{
	int mid;

	while(left<=right)
	{
		mid = (left+right)/2;
		if ( x == a[mid] )
			return mid;
		else if(x < a[mid])
			right = mid-1;
		else if(x > a[mid])
			left = mid+1;
	}
	return -1;
}

int main()
{
	fin >>n >> el;
	for(int i = 1; i<= n; i++ )
		fin>>a[i];
	sort(a+1,a+n+1);
	
	fout << BinarySearch(el,1,n);

	fin.close();
	fout.close();
	return 0;
}
