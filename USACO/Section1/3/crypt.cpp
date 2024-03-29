/*
ID: firstaw1
PROG: crypt1
LANG: C++
*/
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

typedef long long ll;
using namespace std;

int a[10],n;

bool judge(int x)
{
	while(x)
	{
		int t=x%10;
		bool found=0;
		for(int i=0;i<n;i++)
			if(a[i]==t)
			{
				found=1;
				break;
			}
		if(!found)
			return false;
		x/=10;
	}
	return true;
}

int main()
{
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int ans=0;
	for(int i=100;i<=999;i++)
		for(int j=10;j<=99;j++)
		{
			if((j%10)*i<=999&&(j%10)*i>=100
					&&(j/10)*i<=999&&(j/10)*i>=100
					&&i*j<=9999&&i*j>=1000
					&&judge(i)&&judge(j)&&judge(i*j)&&judge((j%10)*i)
					&&judge((j/10)*i))
			{
	//			cout<<i<<' '<<j<<' '<<i*j<<endl;
				ans++;
			}
		}
	printf("%d\n",ans);
	return 0;
}
