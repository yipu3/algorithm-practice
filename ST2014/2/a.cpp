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
#include<cmath>
#include<sstream>
#include<string>

typedef long long ll;
using namespace std;

int a[16];

int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k;
		scanf("%d",&k);
		for(int i=0;i<15;i++)
			scanf("%d",&a[i]);
		int cnt=0;
		for(int i=1;i<14;i++)
			for(int d=0;i+d<14;d++)
			{
				bool flag=true;
				for(int j=i;j<=i+d;j++){
					if(a[j]<=a[i-1]||a[j]<=a[i+d+1]){
						flag=false;
						break;
					}
				}
				if(flag)
					cnt++;
			}
		printf("%d ",k);
		printf("%d\n",cnt);
	}
	return 0;
}
