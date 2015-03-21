#include <fstream>
using namespace std;
ifstream fin("disjoint.in");
ofstream fout("disjoint.out");

int t[100001], rrank[100001];

inline int GetRoot(int x)
{
	while(t[x]!=x)
		x=t[x];
	return x;
}

inline void Unite(int x, int y)
{
	x=GetRoot(x);
	y=GetRoot(y);
	if(rrank[y]<rrank[x])
		t[y]=x;
	else
	{
		t[x] = y;
		if(rrank[x]==rrank[y])
			rrank[y]++;
	}
}

int main()
{
	int n, m, op, x, y;
	fin>>n>>m;
	for(int i = 1; i<= n; i++ )
		t[i]=i;
	for(int i = 1; i<= m; i++ )
	{
		fin>>op>>x>>y;
		if(op==1)
		{
			Unite(x,y);
		}
		else
			fout << (GetRoot(x)==GetRoot(y)?"DA":"NU")<<'\n';
	}
	fin.close();
	fout.close();
	return 0;
}
