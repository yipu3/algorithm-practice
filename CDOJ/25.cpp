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

int a[10],b[10],sa,sb;

char ch(int x)
{
	if(x==0)
		return 'X';
	else if(x==1)
		return 'O';
	else
		return '-';
}

int main()
{
	int n;
	while(~scanf("%d",&n)&&n)
	{
		getchar();
		int cnta=0;
		int cntb=0;
		string s;
		memset(a,-1,sizeof(a));
		memset(b,-1,sizeof(b));
		for(int i=0;i<n;i++)
		{
			getline(cin,s);
			if(i%2==0)
			{
				if(s.find(" no good")==s.size()-8)
					a[cnta++]=0;
				else
					a[cnta++]=1;
			}
			else
			{
				if(s.find(" no good")==s.size()-8)
					b[cntb++]=0;
				else
					b[cntb++]=1;
			}
		}
		sa=sb=0;
		for(int i=1;i<=(n+1)/2;i++)
			printf("%d ",i);
		printf("Score\n");
		for(int i=0;i<(n+1)/2;i++)
		{
			if(a[i]==1)
				sa++;
			printf("%c ",ch(a[i]));
		}
		printf("%d\n",sa);
		for(int i=0;i<(n+1)/2;i++)
		{
			if(b[i]==1)
				sb++;
			printf("%c ",ch(b[i]));
		}
		printf("%d\n",sb);
	}
	return 0;
}
