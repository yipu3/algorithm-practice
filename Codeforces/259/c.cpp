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
	int m,n;
	cin>>m>>n;
	double ans=0;
	for(int i=1;i<=m;i++){
		double tmp=i,tm=m;
		ans+=tmp*(pow(tmp/tm,n)-pow((tmp-1)/tm,n));
	}
	printf("%.10f",ans);
	return 0;
}
