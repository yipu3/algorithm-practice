#include<cstdio>
#define maxn 50000
#define ll long long
ll x[maxn],y[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld",&x[i],&y[i]);
	}
	int max=0;
	int ans=-1;
	int dx,dy;
	if((y[1]-y[0])*(x[2]-x[0])!=(x[1]-x[0])*(y[2]-y[0]))
		max++;
	if((y[2]-y[0])*(x[3]-x[0])!=(x[2]-x[0])*(y[3]-y[0]))
		max++;
	if((y[1]-y[0])*(x[3]-x[0])!=(x[1]-x[0])*(y[3]-y[0]))
		max++;
	//printf("%d\n",max);
	if(max==3)
		ans=0;
	if(max==0)
	{
		dx=x[1]-x[0];
		dy=y[1]-y[0];
	}
	else
	{
		dx=x[4]-x[0];
		dy=y[4]-y[0];
	}
	if(ans==-1)
	{
		for(int i=1;i<n;i++)
			if((x[i]-x[i-1])*dy!=dx*(y[i]-y[i-1]))
			{
				ans=i;
				break;
			}
	}
	printf("%lld %lld\n",x[ans],y[ans]);
}
