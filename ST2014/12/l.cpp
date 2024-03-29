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

struct node{
	int num,ind;
}tt[20005];

bool cmp(const node &a,const node &b){
	return a.num<b.num;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,l;
		scanf("%d%d",&n,&l);
		for(int i=0;i<n;i++){
			int s,f,m;
			scanf("%d:%d:%d",&s,&f,&m);
			tt[i].num=s*3600+f*60+m;
			tt[i].ind=i+1;
		}
		sort(tt,tt+n,cmp);
		int last=0,cnt=1;
		vector<int> ans;
		ans.push_back(tt[0].ind);
		for(int i=1;i<n;i++){
			if(tt[i].num-tt[last].num>=l){
				cnt++;
				ans.push_back(tt[i].ind);
				last=i;
			}
		}
		sort(ans.begin(),ans.end());
		printf("%d\n",cnt);
		printf("%d",ans[0]);
		for(int i=1;i<ans.size();i++){
			printf(" %d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
