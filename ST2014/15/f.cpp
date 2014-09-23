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
typedef unsigned long long ull;
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&f[i]);
		bool flag=true;
		if(f[1]%f[0]!=0)
			flag=false;
		if(flag){
			int x=f[1]/f[0];
			for(int i=1;i<n;i++)
				if(f[i]!=f[i-1]*x){
					flag=false;
					break;
				}
		}
		if(flag){
			printf("%d\n",f[n-1]*x);
			continue;
		}else{
			flag=true;
			int a=f[0],b=f[1],c=f[2],d=f[3];
			if(((b*c-a*d)%(b*b-a*c)!=0)||((c*b*b-a*c*c-b*b*c+a*b*d)%(a*(b*b-a*c)))!=0)
				flag=false;
			if(flag){
				int x=(b*c-a*d)/(b*b-a*c);
				int y=(c*b*b-a*c*c-b*b*c+a*b*d)/(a*(b*b-a*c));
				for(int i=4;i<n;i++)
					if(f[i]!=x*f[i-2]+y*f[i-1]){
						flag=false;
						break;
					}
			}
			if(flag){
				printf("%d\n",x*f[n-2]+y*f[n-1]);
			}else{
				
			}
		}
	}
	return 0;
}
