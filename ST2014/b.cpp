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

vector<string> ss;
char tmp[25];
char grid[25][25];

int main(){
	int h,w;
	while(~scanf("%d%d",&h,&w)){
		for(int i=0;i<h;i++){
			scanf("%s",tmp);
			for(int j=0;j<w;j++)
				grid[i][j]=tmp[j];
		}
		ss.clear();
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++){
				int x=i+1,y=j-1;
				string tmp;
				tmp+=grid[i][j];
		//		cout<<i<<' '<<j<<'!'<<endl;
				int cnt=0;
				while(1){
					cnt++;
					if(cnt>=15)
						break;
		//			cout<<1<<endl;
					if(x>=h)
						x-=h;
					if(y<0)
						y+=w;
					if(x==i&&y==j)
						break;
		//			cout<<x<<' '<<y<<' '<<grid[x][y]<<endl;
					tmp+=grid[x][y];
					x++;y--;
				}
				cout<<i<<' '<<j<<' '<<tmp<<endl;
		//		cout<<tmp<<endl;
				ss.push_back(tmp);
				string tmp2;
				tmp2+=grid[i][j];
				x=i-1;y=j+1;
				while(1){
					if(x<0)
						x+=h;
					if(y>=w)
						y-=w;
					if(x==i&&y==j)
						break;
					tmp2+=grid[x][y];
					x--;y++;
				}
				ss.push_back(tmp2);
			}
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++){
				int x=i+1,y=j+1;
				string tmp;
				tmp+=grid[i][j];
				while(1){
					if(x>=h)
						x-=h;
					if(y>=w)
						y-=w;
					if(x==i&&y==j)
						break;
					tmp=tmp+grid[x][y];
					x++;y++;
				}
				ss.push_back(tmp);
				string tmp2;
				tmp2+=grid[i][j];
				x=i-1;y=j-1;
				while(1){
					if(x<0)
						x+=h;
					if(y<0)
						y+=w;
					if(x==i&&y==j)
						break;
					tmp2=tmp2+grid[x][y];
					x--;y--;
				}
//				if(tmp2.size()==1)
//					cout<<i<<' '<<j<<'!'<<endl;
				ss.push_back(tmp2);
			}
		string ans;int maxx=0;
		sort(ss.begin(),ss.end());
		for(int i=0;i<ss.size()-1;i++)
			if(ss[i]==ss[i+1]){
				maxx=h*w;
				ans=ss[i];
				break;
			}
		if(maxx!=0){
			cout<<ans<<endl;
			continue;
		}
		//竖行
		ss.clear();
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++){
				int k=i+1;
				string tmp;
				tmp+=grid[i][j];
				while(1){
					if(k>=h)
						k-=h;
					if(k==i)
						break;
					tmp=tmp+grid[k][j];
					k++;
				}
				ss.push_back(tmp);
				k=i-1;
				string tmp2;
				tmp2+=grid[i][j];
				while(1){
					if(k<0)
						k+=h;
					if(k==i)
						break;
					tmp2=tmp2+grid[k][j];
					k--;
				}
				ss.push_back(tmp2);
			}
		sort(ss.begin(),ss.end());
		for(int i=0;i<ss.size()-1;i++)
			if(ss[i]==ss[i+1]){
				maxx=h;
				ans=ss[i];
				break;
			}
		if(maxx>w){
			cout<<ans<<endl;
			continue;
		}
		//横行
		ss.clear();
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++){
				int k=j+1;
				string tmp;
				tmp+=grid[i][j];
				while(1){
					if(k>=w)
						k-=w;
					if(k==j)
						break;
					tmp=tmp+grid[i][k];
					k++;
				}
				ss.push_back(tmp);
				string tmp2;
				tmp+=grid[i][j];
				k=j-1;
				while(1){
					if(k<0)
						k+=w;
					if(k==j)
						break;
					tmp2=tmp2+grid[i][k];
					k--;
				}
				ss.push_back(tmp2);
			}
		cout<<1<<endl;
		sort(ss.begin(),ss.end());
		for(int i=0;i<ss.size()-1;i++)
			if(ss[i]==ss[i+1]){
				if(maxx<w){
					maxx=w;
					ans=ss[i];
					break;
				}else if(maxx==w){
					if(ans>ss[i])
						ans=ss[i];
					break;
				}
			}
		cout<<ans<<endl;
	}
	return 0;
}
