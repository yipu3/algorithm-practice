#include<iostream>
#include<cmath>
bool can[1000005];
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=1000;i++)
		can[i*i]=true;
	for(int x1=-a;x1<0;x1++)
		for(int x2=b;x2>0;x2--)
		{
			if(!can[a*a-x1*x1]||!can[b*b-x2*x2])
				continue;
			double y1=sqrt(a*a-x1*x1);
			double y2=sqrt(b*b-x2*x2);
			if(y1!=y2&&x1*x2+y1*y2==0)
			{
				cout<<"YES\n";
				cout<<"0 0"<<endl;
				cout<<x1<<' '<<y1<<endl;
				cout<<x2<<' '<<y2<<endl;
				return 0;
			}
		}
	cout<<"NO"<<endl;
	return 0;
}
