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

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int isprime[MAXN];

int judge(string x){
	int res=0;
	for(int i=0;i<x.size();i++){
		res=res*10+x[i]-'0';
	}
//	cout<<res<<endl;
	if(res>100000)
		return 0;
	if(isprime[res])
		return res;
	else
		return 0;
}
int main(){
	string s;
	for(int i=0;i<MAXN;i++)
		isprime[i]=1;
	isprime[0]=isprime[1]=0;
	for(int i=2;i<MAXN;i++){
		if(isprime[i]){
			for(int j=2*i;j<MAXN;j+=i)
				isprime[j]=0;
		}
	}
	while(cin>>s&&s!="0"){
		string tmp;
		int maxx=0;
		for(int i=0;i<s.size();i++)
			for(int j=i;j<i+6;j++){
				tmp=s.substr(i,j-i+1);
				int tt=judge(tmp);
				if(tt!=0)
					maxx=max(tt,maxx);
			}
		printf("%d\n",maxx);
	}
	return 0;
}
