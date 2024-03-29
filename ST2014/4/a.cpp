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

int mark[805];

int main(){
	int t;
	for(int i=1;i<=800;i++){
		if(i%7==0){
			mark[i]=1;
		}else{
			int tmp=i;
			while(tmp){
				if(tmp%10==7){
					mark[i]=1;
					break;
				}else{
					tmp/=10;
				}
			}
		}
	}
//	for(int i=1;i<=100;i++){
//		cout<<i<<' '<<mark[i]<<endl;
//	}
	scanf("%d",&t);
	while(t--){
		int p;
		scanf("%d",&p);
		bool flag=false;
		int cnt=0;
		int ans;
		for(int i=1;;i++){
			if(mark[i]&&!flag){
				cnt=1;
				if(cnt==p){
					ans=i;
					break;
				}
				flag=true;
			}else if(!mark[i]&&flag){
				flag=false;
				cnt=0;
			}else if(mark[i]&&flag){
				cnt++;
				if(cnt==p){
					ans=i-cnt+1;
					break;
				}
			}else
				cnt=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}
