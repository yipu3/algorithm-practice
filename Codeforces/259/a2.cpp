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

char grid[105][105];

int main(){
	int n;
	cin>>n;
	int be=n/2,cnt=0;
	for(int i=0;i<n/2;i++)
		for(int j=0;j<n;j++){
			if(j==be){
				for(;j<=be+cnt;j++)
					grid[i][j]='D';
				be--;
				cnt+=2;
			}
		}
	for(int j=0;j<n;j++)
		grid[n/2][j]='D';
	be=1;cnt=n-3;
	for(int i=n/2+1;i<n;i++)
		for(int j=0;j<n;j++){
			if(j==be){
				for(;j<=be+cnt;j++)
					grid[i][j]='D';
				be++;
				cnt-=2;
			}
		}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(grid[i][j]!='D'){
				cout<<'*';
			}else
				cout<<'D';
		cout<<endl;
	}
	return 0;
}
