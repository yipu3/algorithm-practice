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

int hash[105][105];
int up[105];
ll fact[100];
ll pp[105];
int cnt1[26],cnt2[26];

int main(){
	int k;
	fact[0]=1;
	for(ll i=1;i<=100;i++){
		fact[i]=fact[i-1]*i;
	}
	while(~scanf("%d",&k)){
		string s1,s2;
		cin>>s1>>s2;
		int n=s1.size();
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		for(int i=0;i<n;i++){
			cnt1[s1[i]-'a']++;
			cnt2[s2[i]-'a']++;
		}
		bool flag=true;
		for(int i=0;i<26;i++)
			if(cnt1[i]!=cnt2[i])
				flag=false;
		memset(hash,0,sizeof(hash));
		for(int i=0;i<k;i++)
			for(int j=0;j<k;j++){
				if(s1[i]==s2[j])
					hash[i][j]=1;
			}
		for(int i=k;i+k<=n;i+=k){
			memset(cnt1,0,sizeof(cnt1));
			memset(cnt2,0,sizeof(cnt2));
			for(int j=i;j<i+k;j++){
				cnt1[s1[j]-'a']++;
				cnt2[s2[j]-'a']++;
			}
			for(int j=0;j<26;j++)
				if(cnt1[j]!=cnt2[j])
					flag=false;
			for(int j=i;j<i+k;j++){
				memset(up,0,sizeof(up));
				for(int d=i;d<i+k;d++){
					if(s1[j]==s2[d]){
						up[d-i]=1;
					}
				}
				for(int d=0;d<k;d++)
					if(hash[j-i][d]==1&&up[d]==0)
						hash[j-i][d]=0;
			}
		}
		memset(pp,0,sizeof(pp));
		ll ans=1;
		for(int i=0;i<k;i++){
			int cnt=0;
			for(int j=0;j<k;j++)
				if(hash[i][j]==1)
					cnt++;
			if(cnt==0)
				flag=false;
			pp[cnt]++;
		}
		if(!flag)
			printf("0\n");
		else{
			for(int i=1;i<=k;i++)
				if(pp[i]!=0){
					pp[i]/=i;
					for(int j=0;j<pp[i];j++)
						ans*=fact[i];
				}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
