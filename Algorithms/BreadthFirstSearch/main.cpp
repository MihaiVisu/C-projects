#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("bfs.in");
ofstream fout("bfs.out");

vector<int>g[100001];
int cost[100001], n, m, s, x, y;
bool vis[100001];
queue<int>q;

void Bfs(int x)
{
	q.push(x);
	for(int i = 1; i<= n; i++ )
		cost[i]=-1;
	cost[x]=0;
	vis[x]=true;
	while(!q.empty())
	{
		x = q.front(); q.pop();
		for(vector<int>::iterator it = g[x].begin(); it < g[x].end(); it++ )
		{
			if(!vis[*it])
			{
				vis[*it]=1;
				cost[*it]=1+cost[x];
				q.push(*it);
			}
		}
	}
}

int main()
{
	fin >> n >> m >> s;
	for (int i = 1; i <= m; ++i)
	{
		fin>>x>>y;
		g[x].push_back(y);
	}

	Bfs(s);

	for(int i = 1; i<= n; i++ )
		fout << cost[i] << ' ';
	fin.close();
	fout.close();
	return 0;
}
