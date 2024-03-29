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
#define MAXN 2010

typedef long long ll;
using namespace std;

int vis[2010];
vector<int> G[1010];
int linked[2010];

bool find(int u)
{
	for(int i=0;i<G[u].size();i++)
	{
		int temp=G[u][i];
		if(!vis[temp])
		{
			vis[temp]=1;
			if(!linked[temp]||find(linked[temp]))
			{
				linked[temp]=u;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n+m;i++){
			G[i].clear();
		}
		char tmp[MAXN];
		for(int i=1;i<=n;i++){
			scanf("%s",tmp);
			for(int j=0;j<m;j++){
				if(tmp[j]=='0'){
					G[i].push_back(j+1+n);
				}else{
					found=1;
				}
			}
		}
		int ans=0;
		memset(linked,0,sizeof(linked));
		for(int i=1;i<=n;i++)
		{
			if(find(i))
				ans++;
			memset(vis,0,sizeof(vis));
		}
//		cout<<n<<' '<<m<<ans<<endl;
		printf("Case %d: %d\n",cas,n+m-ans);
	}
	return 0;
}
