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
	ll l,p,v;
	int cas=0;
	while(~scanf("%lld%lld%lld",&l,&p,&v)&&(l||p||v)){
		cas++;
		ll ans=0;
		ans+=v/p*l;
		ans+=v%p;
		printf("Case %d: ",cas);
		printf("%lld\n",ans);
	}
	return 0;
}
