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

int a[205];

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			a[n+i]=a[i];
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			int tmp=0;
			for(int j=i;j<i+m;j++)
			{
				tmp+=a[j];
			}
			if(tmp>ans)
				ans=tmp;
		}
		cout<<ans<<endl;
	}
	return 0;
}
