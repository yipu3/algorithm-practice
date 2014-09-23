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

int a[105][105];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	if(n%2==1)
	{
		cout<<n;
		return 0;
	}
	else
	{
		int t=n;
		while(1)
		{
			int s=t/2-1;
			int u=s,d=s+1;
			int flag=1;		
			for(int i=0;i<t/2;i++)
			{
				for(int j=0;j<m;j++)
					if(a[i][j]!=a[t-i-1][j])
					{
						flag=0;
						break;
					}
			}
			if(!flag||t==1)
				break;
			if(t%2==1)
				break;
			t/=2;
		}
		cout<<t;
	}
	return 0;
}
