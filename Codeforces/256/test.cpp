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
using namespace std;

bool check(string &a,string &b){
	int poss=0,post=0;
	int a1,b1;
	a1=a.size();
	b1=b.size();
	for(poss=0;poss<a1;poss++){
		while(post<b1&&b[post]!=a[poss])
			post++;
		if(post==b1)
			return false;
		post++;
	}
	return true;
}
int main(){
	string s,t;
	cin>>s>>t;
	if(check(t,s))
		cout<<'!'<<endl;
	return 0;
}
