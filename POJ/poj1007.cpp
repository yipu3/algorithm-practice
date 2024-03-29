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
#define MAXN 105

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

struct node{
	string s;
	int so;
	int ord;
}all[MAXN];

int cal(string s){
	int res=0;
	for(int i=0;i<s.size();i++){
		for(int j=i+1;j<s.size();j++)
			if(s[i]>s[j])
				res++;
	}
	return res;
}

bool cmp(const node &a,const node &b){
	if(a.so==b.so)
		return a.ord<b.ord;
	else
		return a.so<b.so;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		cin>>all[i].s;
		all[i].so=cal(all[i].s);
		all[i].ord=i;
	}
	sort(all,all+m,cmp);
	for(int i=0;i<m;i++)
		cout<<all[i].s<<endl;
	return 0;
}
