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

int main(){
	double ans=0;
	int n,m;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		double tmp=(double)i;
		ans+=tmp*(pow(tmp/m,n)-pow((tmp-1.0)/m,n));
	}
	printf("%.10f",ans);
	return 0;
}
