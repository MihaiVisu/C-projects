#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ifstream fin("f.in");
ofstream fout("f.out");

int n,m,v1[1001],v2[1001], res[1001];

inline void Add(string a, string b)
{

	//parsing the numbers

	for(int i = a.length() -1; i >= 0; i-- )
		v1[++n]= a[i]-'0';
	for(int i = b.length() -1; i >= 0; i-- )
		v2[++m] = b[i]-'0';

	int t = 0;
	for( int i =  1; i<= min(m,n); i++ )
	{
		int addDigit = v1[i]+v2[i]; // adding digit by digit
		res[i] = addDigit%10+t;
		t = addDigit/10;
	}

	res[min(m,n)+1]=v1[min(m,n)+1]+v2[min(m,n)+1]+t;
	for(int i = min(m,n)+2; i <= max(m,n); i++ )
		res[i]=v1[i]+v2[i];
	for(int i = max(m,n); i >= 1; i-- )
		fout<<res[i];

}

int main()
{
	string a,b;
	fin>>a>>b;

	Add(a,b);
	
	fin.close();
	fout.close();
	return 0;
}
