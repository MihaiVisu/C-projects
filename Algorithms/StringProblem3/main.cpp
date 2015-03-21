#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("f.in");

int main()
{
	char s[101];
	fin >> s;
	for (int i = 0; i < strlen(s); ++i)
	{
		if(strchr("aeiou",s[i]))
			s[i]=s[i]+'A'-'a';
	}
	cout<<s<<'\n';
}