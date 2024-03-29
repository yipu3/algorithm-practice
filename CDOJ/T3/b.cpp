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
#define MAXN 500

typedef long long ll;
using namespace std;

int val[MAXN];
int G[MAXN][MAXN];

int main()
{
	int v,e;
	while(~scanf("%d%d",&v,&e))
	{
		for(int i=0;i<v;i++)
			scanf("%d",&val[i]);
		memset(G,0,sizeof(G));
		while(e--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			G[a-1][b-1]=G[b-1][a-1]=1;
		}
		int ans=0;
		for(int i=0;i<v;i++)
			for(int j=i+1;j<v;j++)
			{
				if(G[i][j])
				{
					ans=max(ans,val[i]+val[j]);
					for(int k=j+1;k<v;k++)
						if(G[k][j]&&G[k][i])
						{
							ans=max(ans,val[i]+val[j]+val[k]);
							for(int r=k+1;r<v;r++)
								if(G[r][i]&&G[r][j]&&G[r][k])
									ans=max(ans,val[i]+val[j]+val[k]+val[r]);
						}
				}
			}
		cout<<ans<<endl;
	}
	return 0;
}
