#include <fstream>
#include <vector>
using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

vector<int> g[100001];
bool vis[100001];
int n, m, x, y, compNr;

inline void Dfs (int x)
{
	if(vis[x]) return;
	vis[x]=true;
	for (vector<int>::iterator i = g[x].begin(); i != g[x].end(); ++i)
		Dfs(*i);
}

int main()
{
	fin>>n >> m;
	for(int i = 1; i<= m; i++ )
	{
		fin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	for(int i = 1; i <= n; i++ )
	{
		if(!vis[i])
		{
			Dfs(i);
			compNr++;
		}
	}
	fout<<compNr<<'\n';
	fin.close();
	fout.close();
	return 0;
}
