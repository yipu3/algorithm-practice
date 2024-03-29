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

int G[35][35];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		memset(G,0,sizeof(G));
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			G[u][v]=G[v][u]=1;
		}
		vector<int> a,b;
		a.push_back(1);
		for(int i=2;i<=n;i++){
			int cnta=0,cntb=0;
			for(int j=0;j<a.size();j++){
				if(G[i][a[j]])
					cnta++;
			}
			for(int j=0;j<b.size();j++){
				if(G[i][b[j]])
					cntb++;
			}
			if(cnta>cntb){
				b.push_back(i);
			}else{
				a.push_back(i);
			}
		}
		printf("%d",a.size());
		for(int i=0;i<a.size();i++){
			printf(" %d",a[i]);
		}
		printf("\n");
		printf("%d",b.size());
		for(int i=0;i<b.size();i++){
			printf(" %d",b[i]);
		}
		printf("\n");
	}
	return 0;
}
