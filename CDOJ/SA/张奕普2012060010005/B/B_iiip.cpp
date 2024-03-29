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

ll ans;

ll ten(ll dep)
{
	int res=1;
	for(int i=0;i<dep;i++)
	{
		res*=10;
	}
	return res;
}

//dfs(n,0,0,len)
void dfs(ll n,ll dep,ll now,ll len)
{
	if((now%(ten(len)))*(now%(ten(len)))%(ten(len))==n)
	{
		if(now<ans)
			ans=now;
		return;
	}
	if(dep==len)
	{
		return;
	}
	for(int i=0;i<10;i++)
	{
		int t1=now+i*ten(dep);
		int t2=n%(ten(dep+1));
	//	if(now==6423)
	//		cout<<t1<<' '<<t2<<' '<<(t1%(ten(dep+1)))*(t1%(ten(dep+1)))%(ten(dep+1))<<endl;
		if(((t1%(ten(dep+1)))*(t1%(ten(dep+1)))%(ten(dep+1)))==t2&&t1<ans)
			dfs(n,dep+1,t1,len);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		char s[11];
		int slen=sprintf(s,"%d",n);
		ans=LONG_LONG_MAX;
		dfs(n,0,0,slen);
		if(ans==LONG_LONG_MAX)
			printf("None\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
