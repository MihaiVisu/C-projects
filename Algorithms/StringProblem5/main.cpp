#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("f.in");

int main()
{
	char s[201];
	fin>>s;
	char c[1];
	c[0]=s[0];
	strcpy(s,s+1);
	strcat(s,c);
	cout<<s<<'\n';
	fin.close();
	return 0;
}
