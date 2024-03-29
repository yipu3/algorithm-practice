/*
ID: firstaw1
PROG: milk
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
#include<set>

typedef long long ll;
using namespace std;

struct node
{
	int pri,amo;
}mi[5005];

bool cmp(const node &a,const node &b)
{
	if(a.pri<b.pri)
		return 1;
	else
		return 0;
}

int main()
{
    freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>mi[i].pri>>mi[i].amo;
	sort(mi,mi+m,cmp);
	int ans=0;
	for(int i=0;i<m;i++)
	{
		if(mi[i].amo<n)
		{
			n-=mi[i].amo;
			ans+=mi[i].pri*mi[i].amo;
		}
		else if(mi[i].amo==n)
		{
			ans+=mi[i].pri*mi[i].amo;
			break;
		}
		else if(mi[i].amo>n)
		{
			ans+=mi[i].pri*n;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
