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
#define MAXN 100100

typedef long long ll;
using namespace std;

int a[MAXN],x[MAXN];

int main(){
	int n,hp;
	while(~scanf("%d%d",&n,&hp)){
		for(int i=0;i<n;i++){
			scanf("%d%d",&x[i],&a[i]);
		}
		int tmp=hp,maxa=0;
		ll ans=0;
		for(int i=0;i<n;i++){
			if(tmp<=x[i]){
				int t=(x[i]-tmp)/maxa+1;
				ans+=t;
				tmp=tmp+t*maxa;
				if(tmp>hp)
					tmp=hp;
				tmp=tmp-x[i];
				maxa=max(maxa,a[i]);
			}else{
				tmp-=x[i];
				maxa=max(maxa,a[i]);
			}
//			cout<<tmp<<' '<<maxa<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
