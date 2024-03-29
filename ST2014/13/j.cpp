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
#define MAXN 100005
#define MAXM 1000005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int head[MAXN],in[MAXN],inn[MAXN],la[MAXN];
int em;
int q1[2*MAXN],q2[2*MAXN];

struct edge{
	int to,next;
}edges[MAXM];

void addedge(int u,int v){
	edges[em].next=head[u];
	edges[em].to=v;
	head[u]=em++;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		em=0;
		scanf("%d%d",&n,&m);
		fill(head,head+n+1,-1);
		fill(in,in+n+1,0);
		for(int i=1;i<=n;i++)
			scanf("%d",&la[i]);
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(v,u);
			in[u]++;
		}
		int s1=0,t1=0,s2=0,t2=0;
//		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
			inn[i]=in[i];
		for(int i=1;i<=n;i++)
			if(inn[i]==0&&la[i]==1){
				q1[t1++]=i;
//				cout<<i<<'!'<<endl;
//				vis[i]=1;
			}
		for(int i=1;i<=n;i++)
			if(inn[i]==0&&la[i]==2){
//				cout<<i<<'?'<<endl;
				q2[t2++]=i;
//				vis[i]=1;
			}
		int last=1,cnt1=-1;
		while(s1!=t1||s2!=t2){
			if(last==1){
					while(s1!=t1){
						int now=q1[s1++];
						for(int e=head[now];e!=-1;e=edges[e].next){
							int v=edges[e].to;
							inn[v]--;
							if(inn[v]==0){
								if(la[v]==1){
									q1[t1++]=v;
								}else
									q2[t2++]=v;
							}
						}
					}
					last=2;
			}else{
					while(s2!=t2){
						int now=q2[s2++];
						for(int e=head[now];e!=-1;e=edges[e].next){
							int v=edges[e].to;
							inn[v]--;
							if(inn[v]==0){
								if(la[v]==2){
									q2[t2++]=v;
								}else
									q1[t1++]=v;
							}
						}
					}
					last=1;
			}
			cnt1++;
		}
//		memset(vis,0,sizeof(vis));
		t1=s1=0;t2=s2=0;
		for(int i=1;i<=n;i++)
			if(in[i]==0&&la[i]==1){
				q1[t1++]=i;
//				vis[i]=1;
			}
		for(int i=1;i<=n;i++)
			if(in[i]==0&&la[i]==2){
				q2[t2++]=i;
//				vis[i]=1;
			}
		last=2;int cnt2=-1;
		while(s1!=t1||s2!=t2){
			if(last==1){
					while(s1!=t1){
						int now=q1[s1++];
						for(int e=head[now];e!=-1;e=edges[e].next){
							int v=edges[e].to;
							in[v]--;
							if(in[v]==0){
								if(la[v]==1){
									q1[t1++]=v;
								}else
									q2[t2++]=v;
							}
						}
					}
					last=2;
			}else{
					while(s2!=t2){
						int now=q2[s2++];
						for(int e=head[now];e!=-1;e=edges[e].next){
							int v=edges[e].to;
							in[v]--;
							if(in[v]==0){
								if(la[v]==2){
									q2[t2++]=v;
								}else
									q1[t1++]=v;
							}
						}
					}
					last=1;
			}
			cnt2++;
		}
//		cout<<cnt1<<' '<<cnt2<<endl;
		printf("%d\n",min(cnt1,cnt2));
	}
	return 0;
}
