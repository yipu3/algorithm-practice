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
#define MAXN 2048580

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll fact(int n){
	ll res=1;
	for(int i=1;i<=n;i++)
		res*=(ll)i;
	return res;
}

vector<int> fac,prime;
int isprime[MAXN];

int main(){
	int x;
	fill(isprime,isprime+MAXN,1);
	isprime[1]=isprime[0]=0;
	for(int i=2;i<MAXN;i++)
		if(isprime[i]){
			prime.push_back(i);
			for(int j=i*2;j<MAXN;j+=i){
				isprime[j]=0;
			}
		}
//	cout<<prime.size()<<endl;
	while(~scanf("%d",&x)){
		fac.clear();
		int allcnt=0;
		for(int i=0;prime[i]<=x;i++){
			if(x%prime[i]==0){
				int cnt=0;
				while(x%prime[i]==0){
					x/=prime[i];
					allcnt++;
					cnt++;
				}
				fac.push_back(cnt);
			}
		}
		ll ans=fact(allcnt);
		for(int i=0;i<fac.size();i++)
			ans/=fact(fac[i]);
		printf("%d %lld\n",allcnt,ans);
	}
	return 0;
}
