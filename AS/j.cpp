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
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,s,t;
		scanf("%d%d%d%d",&n,&m,&s,&t);
		memset(head,-1,sizeof(head));
		em=0;
		while(m--){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
		}
		printf("%d")
	}
	return 0;
}
