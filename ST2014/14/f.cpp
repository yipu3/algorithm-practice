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

//int f[MAXN],d[MAXN],l[MAXN];

int main(){
	int n;
	scanf("%d",&n);
	if(n==0){
		printf("0.000\n");
		return 0;
	}
	int ans=0;
	for(int i=3;i<=n+2;i++){
		ans+=(i/2)*(i-i/2);
	}
	ans--;
	printf("%d.000\n",ans);
	return 0;
}
