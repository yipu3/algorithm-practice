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
	string s;
	cin>>s;
	int k;
	cin>>k;
	for(int i=0;i<k;i++)
		s=s+'*';
	int hl=s.size()/2;
	int ans=0;
	for(int i=1;i<=hl;i++)
		for(int j=0;j<s.size();j++){
			if(j+2*i>s.size())
				break;
			bool flag=true;
			for(int k=j;k<j+i;k++)
				if(s[k]!=s[k+i]&&s[k]!='*'&&s[k+i]!='*'){
					flag=false;
					break;
				}
			if(flag)
				ans=max(ans,i);
		}
	cout<<2*ans;
	return 0;
}
