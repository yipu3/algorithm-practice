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

int a[MAXN],b[MAXN];
int d[MAXN],t[MAXN];
int hashd[MAXN],hasht[MAXN];

struct node{
	int amo,ind;
}dt[MAXN],tt[MAXN];

bool cmp(const node &a,const node &b){
	return a.amo<b.amo;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&d[i]);
		dt[i].amo=d[i];
		dt[i].ind=i;
	}
	for(int i=0;i<m;i++){
		scanf("%d",&t[i]);
		tt[i].amo=t[i];
		tt[i].ind=i;
	}
	fill(hashd,hashd+m,n+1);
	fill(hasht,hasht+m,n+1);
	sort(dt,dt+m,cmp);sort(tt,tt+m,cmp);
	int i=0,j=0;
	while(i<m){
		while(a[j]<=dt[i].amo&&j<n)
			j++;
		if(j==n)
			break;
		else
			hashd[dt[i].ind]=j;
		i++;
	}
	i=j=0;
//	for(int i=0;i<m;i++)
//		cout<<hashd[i]<<' ';
//	cout<<endl;
	while(i<m){
		while(b[j]<=tt[i].amo&&j<n)
			j++;
		if(j==n)
			break;
		else
			hasht[tt[i].ind]=j;
		i++;
	}
//	cout<<1<<endl;
	for(int i=0;i<m;i++){
		int tmp1,tmp2;
		tmp1=hashd[i];tmp2=hasht[i];
//		cout<<tmp1<<' '<<tmp2<<endl;
		if(tmp1>tmp2)
			cout<<"Constantine"<<endl;
		else if(tmp1<tmp2)
			cout<<"Mike"<<endl;
		else
			cout<<"Draw"<<endl;
	}
	return 0;
}
