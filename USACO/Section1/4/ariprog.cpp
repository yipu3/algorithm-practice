/*
ID: firstaw1
PROG: ariprog
LANG: C++
*/
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

const int MAXN=250*250*2+100;

bool mark[MAXN];
int num[MAXN];

int maxx;
bool dfs(int m,int d,int n){
	if(m+n*d>maxx)
		return false;
	if(n==0)
		return true;
	if(mark[m+d])
		if(dfs(m+d,d,n-1))
			return true;
	return false;
}

struct node{
	int a,b;
	node(int a=0,int b=0):a(a),b(b){
		//
	}
};

vector<node> A;

bool cmp(const node &a,const node &b){
	if(a.b==b.b)
		return a.a<b.a;
	else
		return a.b<b.b;
}

int main(){
	freopen("ariprog.in","r",stdin);
    freopen("ariprog.out","w",stdout);
	int n,m,cnt=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=m;i++)
		for(int j=i;j<=m;j++)
			if(mark[i*i+j*j]==false){
				mark[i*i+j*j]=true;
				num[cnt++]=i*i+j*j;
			}
	sort(num,num+cnt);
	maxx=num[cnt-1];
	for(int i=0;i<cnt;i++)
		for(int j=i+1;j<cnt;j++){
			if(dfs(num[i],num[j]-num[i],n-1))
				A.push_back(node(num[i],num[j]-num[i]));
		}
	if(A.size()==0){
		printf("NONE\n");
		return 0;
	}
	sort(A.begin(),A.end(),cmp);
	for(int i=0;i<A.size();i++)
		printf("%d %d\n",A[i].a,A[i].b);
	return 0;
}
