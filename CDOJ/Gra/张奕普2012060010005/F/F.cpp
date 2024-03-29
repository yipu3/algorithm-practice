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

priority_queue<int> pque;
queue<int> q;
int n,sum;

bool judge()
{
	int u;
	for(int i=0;i<n;i++)
	{
//		sort(a+i,a+n,cmp);
		u=pque.top();
		pque.pop();
		if(u>n-i-1)
			return false;
		if(u==0)
			return true;
		for(int i=0;i<u;i++)
		{
			int v=pque.top();
			pque.pop();
			v--;
			if(v<0)
				return false;
			else
				q.push(v);
		}
		while(!q.empty())
		{
			int temp=q.front();
			q.pop();
			pque.push(temp);
		}
	}
	return true;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d",&n);
		while(!pque.empty())
			pque.pop();
		while(!q.empty())
			q.pop();
		for(int i=0;i<n;i++)
		{
			int temp;
			scanf("%d",&temp);
			sum+=temp;
			pque.push(temp);
		}
		if(sum%2)
		{
			printf("NO\n");
			continue;
		}
		if(judge())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
