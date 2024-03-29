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

struct ca
{
	ll x,v;
}car[100010];

ll n,mm;

bool cmp(const ca &a,const ca &b)
{
	if(a.x<b.x)
		return true;
	else if(a.x==b.x)
		return a.v>b.v;
	else
		return false;
}

ll c[1000010];

ll lowbit(ll x)
{
    return x&-x;
}

ll sum(ll x)
{
    ll ret=0;
    while(x>0)
    {
        ret+=c[x];
        x-=lowbit(x);
    }
    return ret;
}

void add(ll x,ll d)
{
    while(x<=mm)
    {
        c[x]+=d;
        x+=lowbit(x);
    }
}

int main()
{
	while(~scanf("%lld",&n))
	{
		memset(c,0,sizeof(c));
		mm=0;
		for(int i=0;i<n;i++)
		{
			ll temp;
			scanf("%lld%lld",&car[i].x,&temp);
			car[i].v=temp+1;
			if(car[i].v>mm)
				mm=car[i].v;
		}
		mm+=2;
		sort(car,car+n,cmp);
//		for(int i=0;i<n;i++)
//			cout<<car[i].v<<' ';
//		cout<<endl;
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			add(car[i].v,1);
			ans+=sum(mm)-(sum(car[i].v));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
