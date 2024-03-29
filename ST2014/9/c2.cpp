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

typedef unsigned long long ull;
using namespace std;

char grid[205][205];
int vis[205][205];

int main(){
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		string s;
		int n,m;
		cin>>s;
		scanf("%d%d",&n,&m);
		int p=s.size();
		while(n*m<p){
			if(n<m)
				n+=m;
			else if(n>m)
				m+=n;
			else
				m*=2;
		}
		int ll=(p-1)/m,lc=(p-1)%m;
		memset(grid,0,sizeof(grid));
		if(p<=m){
			for(int i=0;i<p;i++)
				grid[0][i]=s[p-1-i];
		}else{
			int cnt=0;
			for(int i=m-1;i>=0;i--)
				for(int j=0;j<=ll;j++){
					if(j==ll&&i>lc)
						continue;
					else
						grid[j][i]=s[cnt++];
				}
		}
		memset(vis,0,sizeof(vis));
		//ll:last line
		for(int i=0;i<ll;i++){
			if(i%2==0){
				for(int j=0;j<m;j++){
					if(vis[i][j])
						continue;
					else{
						char tmp=grid[i][j];
						if(j==m-1){
							if(i+1==ll)
								break;
							else{
								grid[i][j]=grid[i+1][j];
								grid[i+1][j]=tmp;
								vis[i][j]=vis[i+1][j]=1;
							}
						}else{
							grid[i][j]=grid[i][j+1];
							grid[i][j+1]=tmp;
							vis[i][j]=vis[i][j+1]=1;
						}
					}
				}
			}else if(i%2==1){
				for(int j=m-1;j>=0;j--){
					if(vis[i][j])
						continue;
					char tmp=grid[i][j];
					if(j==0){
						if(i+1==ll)
							break;
						else{
							grid[i][j]=grid[i+1][j];
							grid[i+1][j]=tmp;
							vis[i][j]=vis[i+1][j]=1;
						}
					}else{
						grid[i][j]=grid[i][j-1];
						grid[i][j-1]=tmp;
						vis[i][j]=vis[i][j-1]=1;
					}
				}
			}
		}
		for(int i=0;i<p;i++){
					char tmp=grid[i/m][i%m]-i/m-i%m-2;
					while(tmp<'a')
						tmp+=26;
					grid[i/m][i%m]=tmp;
		}
		printf("Case #%d: ",cas);
		for(int i=0;i<p;i++)
			printf("%c",grid[i/m][i%m]);
		printf("\n");
	}
	return 0;
}
