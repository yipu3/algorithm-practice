#include<cstdio>
#include<cstring>

typedef unsigned long long ull;
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		char s[105];
		int n,m;
		scanf("%s%d%d",s,&n,&m);
		int p=strlen(s);
		while(n*m<p){
			if(n<m)
				n+=m;
			else if(n>m)
				m+=n;
			else
				m*=2;
		}
		int r=(p-1)/m,e=(p-1)%m+1;
		char grid[n][m];
		memset(grid,-1,sizeof(grid));
/*		if(p<=m){
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
		}*/
		int cnt=0;
		for(int i=m-1;i>=0;i--){
			if(i<e){
				for(int j=0;j<r+1;j++){
					grid[j][i]=s[cnt++];
				}
			}else{
				for(int j=0;j<r;j++){
					grid[j][i]=s[cnt++];
				}
			}
		}
/*		if(m%2==0){
			for(int i=0;i<r;i++)
				for(int j=0;j<m/2;j++){
					char tmp=grid[i][j*2];
					grid[i][j*2]=grid[i][j*2+1];
					grid[i][j*2+1]=tmp;
				}
		}else{
			for(int i=0;i<r;i++){
				for(int j=0;j<m/2;j++){
					char tmp=grid[i][j*2];
					grid[i][j*2]=grid[i][j*2+1];
					grid[i][j*2+1]=tmp;
				}
			}
			for(int i=0;i<r/2;i++){
				char tmp=grid[i*2][m-1];
				grid[i*2][m-1]=grid[i*2+1][m-1];
				grid[i*2+1][m-1]=tmp;
			}
		}*/
		if (m % 2)
		{
			for (int i = 0; i < r; ++i)
			{
				for (int j = 0; j < m / 2; ++j)
				{
					char c = grid[i][j * 2];
					grid[i][j * 2] = grid[i][j * 2 + 1];
					grid[i][j * 2 + 1] = c;
				}
			}
			for (int i = 0; i < r / 2; ++i)
			{
				char c = grid[i * 2][m - 1];
				grid[i * 2][m - 1] = grid[i * 2 + 1][m - 1];
				grid[i * 2 + 1][m - 1] = c;
			}
		}
		else
		{
			for (int i = 0; i < r; ++i)
			{
				for (int j = 0; j < m / 2; ++j)
				{
					char c = grid[i][j * 2];
					grid[i][j * 2] = grid[i][j * 2 + 1];
					grid[i][j * 2 + 1] = c;
				}
			}
		}
		//ll:last line
		/*
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
		}*/
		printf("Case #%d: ",cas);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (grid[i][j] > 0)
				{
					int c = grid[i][j] - i - j - 2;
					while (c < 'a')
					{
						c += 26;
					}
					printf("%c", c);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
