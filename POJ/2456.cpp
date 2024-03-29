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
#define MAXN 100005

typedef long long ll;
using namespace std;

int a[MAXN];
int n,c;

bool judge(int x)
{
	int i=0,cnt=1;
	for(int j=i+1;j<n;j++)
	{
		if(a[j]-a[i]>=x)
		{
			cnt++;
			i=j;
		}
	}
//	if(x==5)
//		cout<<cnt<<endl;
	return cnt>=c;
}

int main()
{
	scanf("%d%d",&n,&c);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int l,r;
	l=0,r=a[n-1]+1;
	while(r-l>1)
	{
		int mid=(r+l)/2;
//		cout<<l<<' '<<r<<endl;
		if(judge(mid))
			l=mid;
		else
			r=mid;
	}
	printf("%d\n",l);
	return 0;
}
