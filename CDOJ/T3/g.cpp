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

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
	int x,y,z;
	while(~scanf("%d%d%d",&x,&y,&z))
	{
		int up=x;
		int down=z-y;
		up*=y;
		int g=gcd(up,down);
		cout<<up/g<<'/'<<down/g<<endl;
	}
	return 0;
}
