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

int sch[1005][1005];

int main(){
	int n,d,k;
	cin>>n>>k>>d;
	bool flag=false;
	int p=1;
	for(int i=0;i<d;i++){
		p=p*k;
		if(p>=n){
			flag=true;
			break;
		}
	}
	if(flag){
		for(int i=0;i<n;i++){
			int cnt=0;
			int tmp=i;
			while(tmp){
				sch[i][cnt++]=tmp%k;
				tmp/=k;
			}
		}
		for(int j=0;j<d;j++){
			cout<<sch[0][j]+1;
			for(int i=1;i<n;i++)
				cout<<' '<<sch[i][j]+1;
			cout<<endl;
		}
	}else{
		cout<<-1;
	}
	return 0;
}
