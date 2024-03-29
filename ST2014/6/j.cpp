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
#define MAXN 505
#define INF 300000

typedef long long ll;
using namespace std;

int r,c,ax,ay,bx,by;

int dx[4]={
	0,0,1,-1
};

int dy[4]={
	1,-1,0,0
};

struct node{
	int x,y,step;
	char c;
};

struct al{
	int x,y;
	char c;
};
vector<al> a;

int d[MAXN][MAXN];
int vis[MAXN][MAXN];
char grid[MAXN][MAXN];

void bfs(){
	memset(vis,0,sizeof(vis));
	queue<node> q;
	node s;
	for(int i=0;i<a.size();i++){
		s.x=a[i].x;s.y=a[i].y;s.c=a[i].c;
		s.step=0;
		grid[s.x][s.y]=s.c;
		d[s.x][s.y]=0;
		q.push(s);
	}
	while(!q.empty()){
/*		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				cout<<grid[i][j];
			cout<<endl;
		}*/
		node now=q.front();q.pop();
		if(grid[now.x][now.y]=='*')
			continue;
		for(int i=0;i<4;i++){
			node nn;
			nn.x=now.x+dx[i];nn.y=now.y+dy[i];nn.step=now.step+1;nn.c=now.c;
			if(nn.x>=0&&nn.x<r&&nn.y>=0&&nn.y<c){
				if(grid[nn.x][nn.y]=='.'){
					grid[nn.x][nn.y]=nn.c;
					d[nn.x][nn.y]=nn.step;
					q.push(nn);
				}else if(grid[nn.x][nn.y]!='#'&&grid[nn.x][nn.y]!=nn.c&&d[nn.x][nn.y]==nn.step)
					grid[nn.x][nn.y]='*';
			}
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&r,&c);
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++){
				d[i][j]=INF;
			}
		a.clear();
		for(int i=0;i<r;i++){
			char tmp[MAXN];
			scanf("%s",tmp);
			for(int j=0;j<c;j++){
				grid[i][j]=tmp[j];
				if(tmp[j]>='a'&&tmp[j]<='z'){
					al tt;
					tt.x=i;tt.y=j;tt.c=tmp[j];
					a.push_back(tt);
				}
			}
		}
		bfs();
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				printf("%c",grid[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
