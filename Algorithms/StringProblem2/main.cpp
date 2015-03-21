#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("f.in");

int main()
{
	char s[101];
	int nrVoc=0;
	fin>>s;
	for(int i = 0; i < strlen(s); i++ )
	{
		if(strchr("aeiou",s[i]))
		{
			nrVoc++;
			strcpy(s+i,s+i+1);
			i--;
		}
	}
	cout << nrVoc << ' ' << s;
	fin.close();
	return 0;
}
