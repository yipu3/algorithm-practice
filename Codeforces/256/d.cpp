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

int main(){
	ll n,m,k;
	cin>>n>>m>>k;
	ll l=0,r=n*m;
	while(r-l>1){
		ll cnt=0;
		ll mid=(l+r)/2;
		for(int i=1;i<=n;i++)
			cnt+=min(mid/i,m);
		if(cnt>=k)
			r=mid;
		else if(cnt<k)
			l=mid;
	}
	printf("%I64d",r);
	return 0;
}
