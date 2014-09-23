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

int a[100005];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int i=n-1;
	while(a[i]>=a[i-1]&&i>0)
		i--;
	if(i==0){
		cout<<0<<endl;
		return 0;
	}
	vector<int> b;
	for(int j=i;j<n;j++)
		b.push_back(a[j]);
	for(int j=0;j<i;j++)
		b.push_back(a[j]);
	sort(a,a+n);
	bool flag=true;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<n-i<<endl;
	return 0;
}
