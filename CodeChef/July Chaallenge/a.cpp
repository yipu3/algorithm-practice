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

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	int t,n;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>s;
		bool flag=false;
		ll cnt=0,ans=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='1')
			{
				cnt++;
			}
		}
		ans=cnt*(cnt-1)/2+cnt;
		cout<<ans<<endl;
	}
	return 0;
}
