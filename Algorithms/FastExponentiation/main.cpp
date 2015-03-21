#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("f.in");
ofstream fout("f.out");

long long Expo(int a, int b)
{
	const int p = 1999999973; // the constant value of the mod
	int n = a, sol=1; // we store the value of a in another variable
	for(int i = 0; (1<<i) <= b; i++ ) // go through the bits of b
	{
		if( (1<<i) & b ) // if i-th bit is 1
			sol = (sol*n)%p; // we add a^(2*i) to solution
		n = (n*n)%p; // we multiply n with n to obtain n^(2*i+1)
	}
	return sol; // we return the solution
}

int main()
{
	int a,b;
	fin>>a>>b;
	fout<<Expo(a,b);
	fin.close();
	fout.close();
	return 0;
}

