#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,p;
		cin>>n>>p;
		int l;
		l=2*n+p;
		for(int i=1;i<=n;i++)
		{
			int flag=0;
			for(int j=i+1;j<=n;j++)
			{
				cout<<i<<' '<<j<<endl;
				l--;
				if(l==0)
				{
					flag=1;
					break;
				}
			}
			if(flag)
				break;
		}
	}
	return 0;
}
