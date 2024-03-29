#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<queue>
#define eps 0.000001 
#define N 100005
#define M 1000005
using namespace std;
int i,j,k,n,m,x,y,T,head[N],ru[N],a[N],ans;
int q0[N],q1[N],q0x,q1x;

struct edgenode
{
	int to,next;
} map[M];

void addedges(int id,int x,int y)
{
	map[id].to=y;
	map[id].next=head[x];
	head[x]=id;
}

void start()
{
	memset(head,-1,sizeof(head));
	memset(map,-1,sizeof(map));
}



void top_sort()
{
	int v;
	bool flag;
	int p=0;
	if (!q1x) ans--;
	
	while (q1x||q0x)
	{
		while (q1x)
		{ 
			i=q1[q1x];
			q1x--;
			for (j=head[i];j!=-1;j=map[j].next)
			{
				v=map[j].to;
				if (!ru[v]) continue;
				ru[v]--;
				if (!ru[v])
				{
					if (a[v]) q1[++q1x]=v;
					else q0[++q0x]=v;
				}
			}
		}
		ans++;
		while (q0x)
		{
			i=q0[q0x];
			q0x--;
			for (j=head[i];j!=-1;j=map[j].next)
			{
				v=map[j].to;
				if (!ru[v]) continue;
				ru[v]--;
				if (!ru[v])
				{
					if (a[v]) q1[++q1x]=v;
					else q0[++q0x]=v;
				}
			}
		}
		ans++;
	}
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		q1x=q0x=ans=0;
		scanf("%d%d",&n,&m);
		for(i=0;i<=n;i++)
			head[i]=-1;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a[i]--;
		}
		for (i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			addedges(i,x,y);
			ru[y]++;
		}
		for (i=1;i<=n;i++)                                                                                                                     
		{
			if (!ru[i])
			{
				if (a[i]) {q1x++;q1[q1x]=i;}
				else {q0x++;q0[q0x]=i;}
			}
		}
		top_sort();
		printf("%d\n",ans-1);
	}
}
