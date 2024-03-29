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

ll dp[2][2];

int main(){
	string s;
	cin>>s;
	int len=s.size();
	ll cnte=0,cnto=0;
	for(int i=0;i<len;i++){
		if(s[i]=='a'){
			dp[i%2][0]++;
			cnto+=dp[i%2][0];
			cnte+=dp[(i+1)%2][0];
		}else{
			dp[i%2][1]++;
			cnto+=dp[i%2][1];
			cnte+=dp[(i+1)%2][1];
		}
	}
	cout<<cnte<<' '<<cnto<<endl;
	return 0;
}
