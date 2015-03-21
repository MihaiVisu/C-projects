#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("f.in");

int main()
{
	char s[201];
	fin>>s;
	for (int i = 0; i < strlen(s)-1; ++i)
	{
		if(s[i]==s[i+1])
		{
			strcpy(s+i,s+i+2);
			if(i>0)
				i--;
			i--;
		}
	}
	cout<<s<<'\n';
}