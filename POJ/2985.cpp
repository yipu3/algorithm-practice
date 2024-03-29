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
#define MAXN 200005

typedef long long ll;
using namespace std;

int num[MAXN],c[MAXN],fa[MAXN];

int lowbit(int x){
	return x&-x;
}

void add(int n,int x){
	while(n<=MAXN){
		c[n]+=x;
		n+=lowbit(n);
	}
}

int sum(int n){
	int ret;
	while(n>=0){
		ret+=c[n];
		n-=lowbit(n);
	}
	return ret;
}

int find(int x){
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}

int find_k(int k){
	int ans=0,cnt=0;
	for(int i=18;i>=0;i--){
		if(ans+(1<<i)>=MAXN||cnt+c[ans+(1<<i)]>=k){
			continue;
		}else{
			ans+=(1<<i);
			cnt+=c[ans];
		}
	}
	return ans+1;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
		num[i]=1;
	add(1,n);
	int sum=n;
	while(m--){
		int c;
		scanf("%d",&c);
		if(c==0){
			int a,b;
			scanf("%d%d",&a,&b);
			int x=find(a),y=find(b);
			if(x!=y){
				fa[x]=y;
				add(num[x],-1);
				add(num[y],-1);
				add(num[x]+num[y],1);
				num[y]=num[y]+num[x];
				num[x]=0;
				sum--;
			}
		}else if(c==1){
			int k;
			scanf("%d",&k);
			int ans=find_k(sum-k+1);
			printf("%d\n",ans);
		}
	}
	return 0;
}
