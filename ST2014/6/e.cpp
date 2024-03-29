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
#define MAXN 3000

typedef long long ll;
using namespace std;

int isprime[MAXN],cnt[MAXN];
vector<int> ans;

int main(){
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<MAXN;i++)
		isprime[i]=1;
	isprime[0]=isprime[1]=0;
	for(int i=2;i<MAXN;i++){
		if(isprime[i]){
			for(int j=2*i;j<MAXN;j+=i){
				isprime[j]=false;
				cnt[j]++;
			}
		}
	}
	int mark=0;
	for(int i=30;i<MAXN;i++)
		if(cnt[i]>=3)
		{
			ans.push_back(i);
		}
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<ans[n-1]<<endl;
	}
	return 0;
}
