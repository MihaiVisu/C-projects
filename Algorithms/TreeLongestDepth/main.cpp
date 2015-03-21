#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("f.in");

vector<int>g[1001];
int n, depth, x, y;
bool vis[1001];

inline void Dfs(int x, int lvl)
{

	if ( lvl > depth)
		depth = lvl;

	if(vis[x]) return;
	vis[x] = true;

	for(vector<int>::iterator it = g[x].begin(); it < g[x].end(); it++ )
	{
		Dfs(*it,lvl+1);
	}
}

int main()
{
	fin >> n;
	for (int i = 0; i < n-1; ++i)
	{
		fin>>x>>y;
		g[x].push_back(y);
	}
	Dfs(1,0);
	cout<<depth << '\n';
	fin.close();
	return 0;
}
