#include<iostream>
using namespace std;
int main()
{
	int n,x;
	cin>>n>>x;
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		sum+=t;
	}
	if(sum==0)
	{
		cout<<'0'<<endl;
		return 0;
	}
	if(sum<0)
		sum=-sum;
	cout<<sum/x+(sum%x==0?0:1)<<endl;
	return 0;
}
