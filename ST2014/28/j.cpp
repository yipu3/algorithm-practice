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

int cnt[26];

int main(){
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		string s;
		cin>>s;
		int n=s.size();
		int ans=0;
		for(int i=0;i<n;i++){
			memset(cnt,0,sizeof(cnt));
			for(int j=i;j<n;j++){
				cnt[s[j]-'a']++;
				int cnto=0;
				int cnte=0;
				for(int k=0;k<26;k++){
					if(cnt[k]%2==0)
						cnte++;
					else
						cnto++;
				}
				if(cnto==1||cnto==0)
					ans++;
			}
		}
		printf("Case %d: ",cas);
		printf("%d\n",ans);
	}
	return 0;
}
