#include<iostream>
#include<cstdio>
using namespace std;
char m[305][305];
int main()
{	
	int n;
	char c1,c2;
	int flag=1;
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%s",m[i]);
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<m[i][j]<<' ';
		cout<<endl;
	}*/
	c1=m[0][0];
	c2=m[0][1];
	if(c1==c2)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(i==j||j==n-i-1)
			{
				if(m[i][j]!=c1)
				{
					flag=0;
					break;
				}
			}
			else if(m[i][j]!=c2)
			{
				flag=0;
				break;
			}
		} 
	if(flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
