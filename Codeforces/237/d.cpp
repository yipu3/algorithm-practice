#include<iostream>
#include<cstdio>
#include<cstring>
const long long m=1000000007;
long long dp[3]={
	1,1,0
};
using namespace std;
int main()
{
	long long t[3];
	char c;
	while((c=getchar())!='\n')
	{
		memset(t,0,sizeof(t));
		if(c=='0'||c=='?')
			t[0]+=dp[0];
		if(c=='1'||c=='?')
		{
			t[0]+=dp[2];
			t[1]+=dp[0];
		}
		if(c=='2'||c=='?')
			t[1]+=dp[2];
		if(c=='*'||c=='?')
			t[2]+=dp[1]+dp[2];
		for(int i=0;i<3;i++)
			dp[i]=t[i]%m;
	}
	printf("%I64d\n",(dp[0]+dp[2])%m);
	return 0;
}
