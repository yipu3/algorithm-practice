#include<iostream>
#include<cstdio>
#include<algorithm>
int m[105];
int k[105];
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k[i]);
	}
	//cout<<"ok"<<endl;
	for(int i=0;i<n;i++)
	{
		int temp;
		for(int j=0;j<k[i];j++)
		{
			scanf("%d",&temp);
			m[i]+=temp*5+15;
		}
	}
	sort(m,m+n);
	cout<<m[0]<<endl;
	return 0;
}
