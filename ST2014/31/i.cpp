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
		int avg,n;
		scanf("%d%d",&avg,&n);
		int sum=avg*n;
		double ans1=0;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n-i;j++)
				for(int k=0;k<=n-i-j;k++)
					for(int r=0;r<=n-i-j-k;r++){
					int s=n-i-j-k-r;
					int tsum=i*60+j*70+k*75+r*80+s*85;
					if(tsum<=sum){
						ans1=max(ans1,i*2.0+j*2.5+k*3.0+r*3.5+s*4.0);
					}
				}
		double ans2=10000.0;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n-i;j++)
				for(int k=0;k<=n-i-j;k++)
					for(int r=0;r<=n-i-j-k;r++){
					int s=n-i-j-k-r;
					int tsum=i*69+j*74+k*79+r*84+s*100;
					if(tsum>=sum){
						ans2=min(ans2,i*2.0+j*2.5+k*3.0+r*3.5+s*4.0);
					}
				}
		printf("%.4f %.4f\n",ans2/n,ans1/n);
	}
	return 0;
}
