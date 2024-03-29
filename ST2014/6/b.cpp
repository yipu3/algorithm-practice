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

int vis[51][51];

bool judgein(int x1,int y1,int x2,int y2,int x3,int y3,int x,int y){
	int s=abs(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);
	int s1=abs(x*y2+x2*y3+x3*y-x*y3-x2*y-x3*y2);
	int s2=abs(x1*y+x*y3+x3*y1-x1*y3-x*y1-x3*y);
	int s3=abs(x1*y2+x2*y+x*y1-x1*y-x2*y1-x*y2);
	if(s==s1+s2+s3)
		return true;
	else
		return false;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		set< pair<int,int> > s;
		int n;
		scanf("%d",&n);
		int ans=0;
		while(n--)
		{
			string c;
			cin>>c;
			if(c=="T"){
				int x1,y1,x2,y2,x3,y3;
				scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
				int maxx=max(x1,max(x2,x3));
				int minx=min(x1,min(x2,x3));
				int maxy=max(y1,max(y2,y3));
				int miny=min(y1,min(y2,y3));
				int cnt=0;
				for(int i=minx;i<=maxx;i++)
					for(int j=miny;j<=maxy;j++)
						if(!s.count(make_pair(i,j))&&judgein(x1,y1,x2,y2,x3,y3,i,j)){
							cnt++;
							s.insert(make_pair(i,j));
						}
				ans+=cnt;
			}else if(c=="C"){
				int x,y,r;
				scanf("%d%d%d",&x,&y,&r);
				int cnt=0;
				for(int i=x-r;i<=x+r;i++)
					for(int j=y-r;j<=y+r;j++){
						if(!s.count(make_pair(i,j))&&(i-x)*(i-x)+(j-y)*(j-y)<=r*r){
							cnt++;
							s.insert(make_pair(i,j));
						}
					}
				ans+=cnt;
			}else{
				int x1,y1,l;
				int cnt=0;
				scanf("%d%d%d",&x1,&y1,&l);
				for(int i=x1;i<=x1+l;i++)
					for(int j=y1;j<=y1+l;j++)
						if(!s.count(make_pair(i,j))){
							s.insert(make_pair(i,j));
							cnt++;
						}
				ans+=cnt;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
