/*
ID: firstaw1
PROG: calfflac
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

string s;

bool isAlpha(char x)
{
	if((x>='a'&&x<='z')||(x>='A'&&x<='Z'))
		return true;
	return false;
}

struct node
{
	char c;int index;
};
vector<node> as;

void findOdd(int i,int &l,int &r)
{
	int tl,tr;
	bool flag=false;
	for(int j=1;i-j>=0&&j+i<as.size();j++)
	{
		if(as[i-j].c!=as[i+j].c)
			break;
		else
		{
			tl=i-j;tr=i+j;
			flag=true;
		}
	}
	if(!flag)
		return;
	else if(tr-tl+1>r-l+1)
	{
		l=tl;r=tr;
	}
}

void findEven(int i,int &l,int &r)
{
	int tl,tr;
	bool flag=false;
	for(int j=0;i-j>=0&&i+j+1<as.size();j++)
	{
		if(as[i-j].c!=as[i+j+1].c)
			break;
		else
		{
			tl=i-j;tr=i+j+1;
			flag=true;
		}
	}
	if(!flag)
		return;
	else if(tr-tl+1>r-l+1)
	{
		l=tl;r=tr;
	}
}

set<int> ss;

int main()
{
    freopen("calfflac.in","r",stdin);
    freopen("calfflac.out","w",stdout);
	string ts;
	while(getline(cin,ts))
	{
		s+=ts;
		if(ts.size()<80)
			ss.insert(s.size()-1);
		ss.insert(s.size()-ts.size()-1);
	}
//	cout<<s<<endl;
	for(int i=0;i<s.size();i++)
		if(isAlpha(s[i]))
		{
			node nn;
			nn.c=toupper(s[i]);
			nn.index=i;
			as.push_back(nn);
		}
	int l=0,r=0;
	for(int i=0;i<as.size();i++)
    {
		findOdd(i,l,r);
		findEven(i,l,r);
	}
	cout<<r-l+1<<endl;
	int cnt=0;
	bool flag=false;
	for(int i=as[l].index;i<=as[r].index;i++)
	{
		cout<<s[i];
		cnt++;
		if(ss.count(i)&&i!=as[r].index)
		{
			cout<<endl;
			cnt=0;
		}
	}
	cout<<endl;
	return 0;
}
