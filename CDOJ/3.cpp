#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		double p,d,t,s;
		double ans;
		scanf("%lf%lf%lf%lf",&p,&d,&t,&s);
		if(d*t>=s)
			ans=s/p;
		else if(d>=p)
			ans=s/p;
		else
		{
			ans=0;
			int sd,sp;
			double T=0;
			while(1)
			{
				T=(d*t)/(p-d);
				if(t+T<(s/d))
				{
					t+=T;
					ans+=T;
				}
				else
					break;
			}
			ans+=s/p;
		}
		printf("Case #%d: %.3lf\n",i+1,ans);
	}
	return 0;
}
