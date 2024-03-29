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
#define MAXN 5005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n,k;
int rank[MAXN];
int tmp[MAXN];
int sa[MAXN],lcp[MAXN];

bool compare_sa(int i,int j){
	if(rank[i]!=rank[j])
		return rank[i]<rank[j];
	else{
		int ri=i+k<=n ? rank[i+k]:-1;
		int rj=j+k<=n ? rank[j+k]:-1;
		return ri<rj;
	}
}

void construct_sa(string S,int *sa){
	n=S.length();
	for(int i=0;i<=n;i++){
		sa[i]=i;
		rank[i]=i<n ? S[i]:-1;
	}
	for(k=1;k<=n;k*=2){
		sort(sa,sa+n+1,compare_sa);
		tmp[sa[0]]=0;
		for(int i=1;i<=n;i++)
			tmp[sa[i]]=tmp[sa[i-1]]+(compare_sa(sa[i-1],sa[i]) ? 1:0);
		for(int i=0;i<=n;i++)
			rank[i]=tmp[i];
	}
}


void construct_lcp(string S,int *sa,int *lcp){
	int n=S.length();
	for(int i=0;i<=n;i++)
		rank[sa[i]]=i;
	int h=0;
	lcp[0]=0;
	for(int i=0;i<n;i++){
		int j=sa[rank[i]-1];
		if(h>0)
			h--;
		for(;j+h<n&&i+h<n;h++){
			if(S[j+h]!=S[i+h])
				break;
		}
		lcp[rank[i]-1]=h;
	}
}

int main(){
	string s1,s2,s;
	cin>>s1>>s2;
	for(int i=0,j=s2.size()-1;i<j;i++,j--){
		char tt=s2[i];
		s2[i]=s2[j];
		s2[j]=tt;
	}
	int len=s1.length();
	s=s1+'$'+s2;
	cout<<s<<endl;
	construct_sa(s,sa);
	construct_lcp(s,sa,lcp);
	int maxx=0;
	int a,b;
	for(int i=0;i<s.length();i++){
		if((sa[i]<len)!=(sa[i+1]<len)){
			a=sa[i];b=sa[i+1];
			if(a>b){
				int tt=a;
				a=b;
				b=tt;
			}
			
		}
	}
	//a<b
	if(a>b){
		int tt=a;
		a=b;
		b=tt;
	}
	a--;
	b--;
	cout<<a<<' '<<b<<endl;
	for(int i=0;i<maxx;i++){
		cout<<s[a+i];
	}
	cout<<endl;
	return 0;
}
