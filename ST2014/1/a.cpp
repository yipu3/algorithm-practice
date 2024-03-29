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
#include<iostream>
#define pi 3.1415927

typedef long long ll;
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		if(n<=3){
			printf("No\n");
			continue;
		}
		else{
			printf("Yes\n");
			vector< pair<double,double> > ans;
			ans.push_back(make_pair(0.0,0.0));
			ans.push_back(make_pair(cos(pi/3),sin(pi/3)));
			ans.push_back(make_pair(1.0,0.0));
			double ta=pi/(3*(n-2));
			for(int i=1;i<=n-3;i++){
				ans.push_back(make_pair(cos(i*ta),sin(i*ta)));
			}
			for(int i=0;i<ans.size();i++)
				printf("%.6lf %.6lf\n",ans[i].first,ans[i].second);
		}
	}
	return 0;
}
