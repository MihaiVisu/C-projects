#include <fstream>
#include <stack>
#include <iostream>
#include <string>
using namespace std;

stack<int>st;
string s;

ifstream fin("f.in");

int main()
{
	string s;
	fin >> s;
	for(int i = 0; i< s.length(); i++ )
	{
		if(s[i]=='[' || s[i] == '(')
			st.push(i);
		else if(s[i] == ')' && s[st.top()] == '(' )
			st.pop();
		else if( s[i] == ']' && s[st.top()] == '[' )
			st.pop();
		else break;
	}
	if( st.empty() )
		cout << "TRUE";
	else cout << "FALSE";
	return 0;
}
