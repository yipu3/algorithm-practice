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

int c[32010],a[100010];

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
	while(x<=32000)
	{
		c[x]+=d;
		x+=lowbit(x);
	}
}

struct node
{
	int x;
	int y;
}boat[100005];

int cmp(const struct node &a,const struct node &b)
{
	if(a.x<b.x)
		return 1;
	if(a.x==b.x)
		if(a.y<b.y)
			return 1;
	return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	int temp;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&boat[i].x,&temp);
		boat[i].y=temp+1;
	}
	sort(boat,boat+n,cmp);
	for(int i=0;i<n;i++)
	{
		add(boat[i].y,1);
		a[sum(boat[i].y)-1]++;
	}
	int i;
	for(i=0;i<n-1;i++)
		printf("%d\n",a[i]);
	printf("%d",a[i]);
	return 0;
}
