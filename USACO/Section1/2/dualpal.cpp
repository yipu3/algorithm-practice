/*
ID: firstaw1
PROG: dualpal
LANG: C++
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<sstream>
#include<vector>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<cmath>
#include<map>
#include<set>

typedef long long ll;
using namespace std;

string cha(int x,int ba)
{
	string s;
	int k=x;
	while(k!=0)
	{
		int t=k%ba;
		if(t>=10)
			s=s+(char)('A'+t-10);
		else
			s=s+(char)('0'+t);
		k/=ba;
	}
	string t;
	for(int i=s.size()-1;i>=0;i--)
		t+=s[i];
	return t;
}

bool judge(string s)
{
	string t;
	for(int i=s.size()-1;i>=0;i--)
		t=t+s[i];
	for(int i=0;i<s.size();i++)
		if(t[i]!=s[i])
			return false;
	return true;
}

int main()
{
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
	int n,s;
	cin>>n>>s;
	int cnt=0;
	for(int i=s+1;;i++)
	{
		int t=0;
		for(int j=2;j<=10;j++)
		{
			if(judge(cha(i,j)))
			{
				t++;
				if(t==2)
				{
					cout<<i<<endl;
					cnt++;
					if(cnt==n)
						return 0;
					break;
				}
			}
		}
	}
	return 0;
}
