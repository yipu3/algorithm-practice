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
	int n,m;
	cin>>n>>m;
	double len=0;
	int ci,cj;
	int a,b,c,d,e,f,g,h;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int k=0;k<=n;k++)
				for(int s=0;s<=m;s++)
					for(int l=0;l<=n;l++)
						for(int r=0;r<=m;r++)
							for(int t=0;t<=n;t++)
								for(int y=0;y<=m;y++){
							if((i==k&&j==s)||(i==l&&j==r)||(i==t&&j==y)||(k==l)&&(s==r)||(k==t)&&(s==y)||(l==t&&r==y))
								continue;
							double tlen=0;
							tlen+=sqrt((i-k)*(i-k)+(j-s)*(j-s));
							tlen+=sqrt((l-k)*(l-k)+(r-s)*(r-s));
							tlen+=sqrt((t-l)*(t-l)+(y-r)*(y-r));
							if(tlen>len){
								len=tlen;
								a=i;b=j;c=k;d=s;e=l;f=r;g=t;h=y;
							}
						}
	cout<<a<<' '<<b<<endl;
	cout<<c<<' '<<d<<endl;
	cout<<e<<' '<<f<<endl;
	cout<<g<<' '<<h<<endl;
	return 0;
}
