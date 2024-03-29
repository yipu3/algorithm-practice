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
#define MAXN 1000005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int a[MAXN];
int c[MAXN];

int lowbit(int x){
	return x&-x;
}

int sum(int x){
	int ret=0;
	while(x>0){
		ret+=c[x];
		x-=lowbit(x);
	}
	return ret;
}

int n;
void add(int x,int d){
	while(x<=n){
		c[x]+=d;
		x+=lowbit(x);
	}
}

map<int,int> m;

int f1[MAXN],f2[MAXN];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
		f1[i]=++m[a[i]];
	m.clear();
	for(int i=n;i>=1;i--)
		f2[i]=++m[a[i]];
	ll ans=0;
	for(int i=n;i>=1;i--){
		ans+=sum(f1[i]-1);
		add(f2[i],1);
	}
	cout<<ans;
	return 0;
}
