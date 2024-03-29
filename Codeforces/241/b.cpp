#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<sstream>
#include<vector>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define maxn 50005

typedef long long ll;
using namespace std;
int ans[maxn];
int t[maxn][5];
int finishtime[5][maxn];

int main()
{
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>t[i][j];
	int a=0;
	finishtime[0][0]=t[0][0];
	for(int i=1;i<m;i++)
		finishtime[0][i]=t[i][0]+finishtime[0][i-1];
//	finishtime[1][0]=finishtime[0][0]+t[0][1];
//	finishtime[1][1]=max(finishtime[0][1],finishtime[1][0]);
/*	for(int i=0;i<m;i++)
		cout<<finishtime[0][i]<<' ';*/
	for(int i=1;i<n;i++)
	{
		finishtime[i][0]=finishtime[i-1][0]+t[0][i];
		for(int j=1;j<m;j++)
			finishtime[i][j]=max(finishtime[i-1][j],finishtime[i][j-1])+t[j][i];
	}
	for(int i=0;i<m;i++)
		cout<<finishtime[n-1][i]<<' ';
	return 0;
}
