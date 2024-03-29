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

ll cnt[26];
vector<ll> a;

bool cmp(const ll &a,const ll &b){
	return a>b;
}

int main(){
	freopen("test.in","r",stdin);
    freopen("b.out","w",stdout);
	ll n,k;
	string s;
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<s.size();i++)
		cnt[s[i]-'A']++;
	for(int i=0;i<26;i++)
		if(cnt[i]!=0)
			a.push_back(cnt[i]);
	sort(a.begin(),a.end(),cmp);
	ll ans=0;
	for(int i=0;i<a.size();i++){
		if(k>=a[i]){
			ans+=a[i]*a[i];
			k-=a[i];
		}else{
			ans+=k*k;
			break;
		}
	}
	cout<<ans;
	return 0;
}
