#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

int main ()
{
	int n, PrimeNr=0;
	n = 100;
	bool prime[10001];
	for(int i= 1; i <= n; i++ )
		prime[i]=1;
	for(int i = 2; i <= n; i++ )
	{
		if(prime[i])
		{
			PrimeNr++;
			for (int j = 2*i; j <= n; j +=i)
			{
				prime[j]=0;
			}
		}
	}
	cout << PrimeNr << '\n';
	for(int i = 2; i <= n; i++ )
		if(prime[i])
			cout << i<<' ';
	return 0;
}
