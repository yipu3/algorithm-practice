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
#define MAXN 100005
#define INF 1e15+5

typedef long long ll;
using namespace std;

int L[MAXN],R[MAXN],h[MAXN];

int main(){
	int n;
	while(~scanf("%d",&n)&&n){
		for(int i=0;i<n;i++)
			scanf("%d",&h[i]);
		stack<int> s;
		for(int i=0;i<n;i++){
			while(!s.empty()&&h[i]<=h[s.top()]){
				s.pop();
			}
			if(s.empty())
				L[i]=0;
			else
				L[i]=s.top()+1;
			s.push(i);
		}
		while(!s.empty())
			s.pop();
		for(int i=n-1;i>=0;i--){
			while(!s.empty()&&h[i]<=h[s.top()]){
				s.pop();
			}
			if(s.empty())
				R[i]=n-1;
			else
				R[i]=s.top()-1;
			s.push(i);
		}
		ll ans=0;
//		cout<<"L:";
//		for(int i=0;i<n;i++)
//			cout<<L[i]<<' ';
//		cout<<"R:";
//		for(int i=0;i<n;i++)
//			cout<<R[i]<<' ';
		for(int i=0;i<n;i++){
			ans=max(ans,(ll)h[i]*(R[i]-L[i]+1));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
