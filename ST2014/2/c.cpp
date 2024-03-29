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
#define MAXN 1005
#define MAXM 1000000

typedef long long ll;
using namespace std;

int head[MAXN],in[MAXN];

struct edge{
	int next,to;
}edges[MAXM];
int em;

struct ord{
	int num,cnt;
}order[MAXN];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int k,m,p;
		scanf("%d%d%d",&k,&m,&p);
		memset(head,-1,sizeof(head));
		memset(in,0,sizeof(in));
		for(int i=1;i<=m;i++)
			order[i].num=order[i].cnt=0;
		em=0;
		while(p--){
			int u,v;
			scanf("%d%d",&u,&v);
			edges[em].next=head[u];
			edges[em].to=v;
			head[u]=em++;
			in[v]++;
		}
		queue<int> q;
		for(int i=1;i<=m;i++)
			if(in[i]==0){
				q.push(i);
				order[i].num=1;
				order[i].cnt=1;
			}
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int e=head[u];e!=-1;e=edges[e].next){
				int v=edges[e].to;
				if(order[u].num>order[v].num){
					order[v].num=order[u].num;
					order[v].cnt=1;
				}else if(order[u].num==order[v].num){
					order[v].cnt++;
				}
				in[v]--;
				if(in[v]==0){
					q.push(v);
//					cout<<"v:"<<v<<endl;
					if(order[v].cnt>1)
						order[v].num++;
				}
			}
		}
/*		for(int i=1;i<=m;i++)
			cout<<order[i].num<<' ';
		cout<<endl;*/
		printf("%d ",k);
		int ans=0;
		for(int i=1;i<=m;i++)
			if(ans<order[i].num)
				ans=order[i].num;
		printf("%d\n",ans);
	}
	return 0;
}
