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
const double pi=3.141592653589793238462643383279;

int main(){
	int n;
	scanf("%d",&n);
	double x,y;
	for(int cas=1;cas<=n;cas++){
		scanf("%lf%lf",&x,&y);
		int i;
		for(i=1;;i++){
			double r=i*50*2/pi;
			if(r>=x*x+y*y)
				break;
		}
		printf("Property %d: This property will begin eroding in year %d.\n",cas,i);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
