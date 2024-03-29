/*
ID: firstaw1
PROG: frac1
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

int gcd(int a,int b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

struct node{
	int up,down;
	double dd;
	node(int up=0,int down=0,double dd=0.0):up(up),down(down),dd(dd){
		//
	}
};
vector<node> ans;

bool cmp(const node &a,const node &b){
	return a.dd<b.dd;
}

int main(){
	freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);
	int n;
	scanf("%d",&n);
	ans.push_back(node(0,1,0.0));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++){
			if(gcd(i,j)==1)
				ans.push_back(node(j,i,double(double(j)/double(i))));
		}
	sort(ans.begin(),ans.end(),cmp);
	for(int i=0;i<ans.size();i++)
		printf("%d/%d\n",ans[i].up,ans[i].down);
	return 0;
}
