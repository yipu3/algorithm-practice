#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<fstream>
#include<sstream>
#include<string>
#define MAXN 1000005

typedef long long ll;
using namespace std;

int a[MAXN],maxx[MAXN],minn[MAXN],deq1[MAXN+100],deq2[MAXN+100];

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int s1=0,t1=0,s2=0,t2=0;
	for(int i=0;i<n;i++)
	{
		while(s1<t1&&a[deq1[t1-1]]>=a[i])
			t1--;
		while(s2<t2&&a[deq2[t2-1]]<=a[i])
			t2--;
		deq1[t1++]=i;
		deq2[t2++]=i;
		if(i-k+1>=0)
		{
			minn[i-k+1]=a[deq1[s1]];
			maxx[i-k+1]=a[deq2[s2]];
			if(deq1[s1]==i-k+1)
				s1++;
			if(deq2[s2]==i-k+1)
				s2++;
		}
	}
	printf("%d",minn[0]);
	for(int i=1;i<n-k+1;i++)
		printf(" %d",minn[i]);
	printf("\n");
	printf("%d",maxx[0]);
	for(int i=1;i<n-k+1;i++)
		printf(" %d",maxx[i]);
	printf("\n");
	return 0;
}
