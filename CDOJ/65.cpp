#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		if(b==13)
			b=12;
		int n=a/b+((a%b)?1:0);
		if(b==14&&a%b==13)
			n+=1;
		if(a==13&&b>=a)
			n=2;
		cout<<n<<endl;
	}
	return 0;
}
