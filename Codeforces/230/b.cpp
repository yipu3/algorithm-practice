/************************************************
 * Author:		iiip
 * File name:		b.cpp
 * Created time:	2014/4/6 21:50:58
 * Email:		firstawhois@gmail.com
 * *********************************************/

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

typedef long long ll;
using namespace std;
double w[180][180];
double a[180][180];
double b[180][180];

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>w[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=(w[i][j]+w[j][i])/2;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			b[i][j]=w[i][j]-a[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n;j++)
			printf("%.8lf ",a[i][j]);
		printf("%.8lf",a[i][n]);
		cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n;j++)
			printf("%.8lf ",b[i][j]);
		printf("%.8lf",b[i][n]);
		cout<<endl;
	}
	return 0;
}
