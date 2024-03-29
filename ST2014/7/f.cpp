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

typedef long long ll;
using namespace std;

int a[MAXN];

priority_queue<int> pque;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,suma=0,sumb=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			suma+=a[i];
		}
		for(int i=0;i<m;i++){
			int tmp;
			scanf("%d",&tmp);
			sumb+=tmp;
			pque.push(tmp);
//			cout<<pque.top()<<endl;
		}
		vector<int> tt;
		for(int i=0;i<n;i++){
			tt.clear();
			for(int j=0;j<a[i];j++){
				int now=pque.top();pque.pop();
				now--;
				tt.push_back(now);
			}
			for(int j=0;j<tt.size();j++)
				pque.push(tt[j]);
		}
		int ans1=0,ans2=0;
		while(!pque.empty()){
			int now=pque.top();
			if(now<0)
				ans1-=now;
			else if(now>0)
				ans2+=now;
			pque.pop();
		}
		printf("%d\n",max(sumb+ans1,suma+ans2));
	}
	return 0;
}
