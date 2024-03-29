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

int c[1010],n;

int lowbit(int x)
{
    return x&-x;
}

int sum(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=c[x];
        x-=lowbit(x);
    }
    return ret;
}

void add(int x,int d)
{
    while(x<=n)
    {
        c[x]+=d;
        x+=lowbit(x);
    }
}

int main()
{
	while(~scanf("%d",&n))
	{
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
		{
			int temp;
			scanf("%d",&temp);
			add(i,temp);
		}
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int i,j;
			scanf("%d%d",&i,&j);
			int temp=(i+j)/2;
//			cout<<temp<<' '<<sum(i-1)<<endl;
			if((i+j)%2==0)
				printf("%d\n",(sum(j)-sum(temp))-(sum(temp-1)-sum(i-1)));
			else
				printf("%d\n",(sum(j)-sum(temp))-(sum(temp)-sum(i-1)));
		}
	}
	return 0;
}
