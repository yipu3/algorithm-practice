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
	double sum=0,tmp;
	for(int i=0;i<12;i++){
		scanf("%lf",&tmp);
		sum+=tmp;
	}
	printf("$%.2lf",sum/12);
	return 0;
}
