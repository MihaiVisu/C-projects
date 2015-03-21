#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;
 
ifstream fin("gcd.in");
ofstream fout("gcd.out");
 
int gcd(int a, int b)
{
    if( a < b)
        swap(a,b);
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}
 
int bin[40];
 
long long expo(int e, int mod)
{
    bin[0] = 0;
    while(e)
    {
        bin[++bin[0]] = e%2;
        e/=2;
    }
    long long sol = 1;
    for(int i = bin[0];i>0;i--)
    {
        sol=(sol*sol)%mod;
        if(bin[i])
            sol = (sol*2) %mod;
    }
    return sol;
}
 
void solve()
{
    int a,b,p;
    fin>>a>>b>>p;
    long long sol = expo(gcd(b,a),p);
    sol -=1 ;
    while(sol < 0)
        sol += p;
    fout<<sol<<'\n';
 
}
 
int main()
{
    int t;
    fin>>t;
    for(int i=1;i<=t;i++)
        solve();
    fin.close();
    fout.close();
    return 0;
}