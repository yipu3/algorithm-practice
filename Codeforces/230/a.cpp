/************************************************
 * Author:		iiip
 * File name:		a.cpp
 * Created time:	2014/4/6 21:35:17
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
int al[27];

int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		al[s[i]-'a']++;
	int ans=0;
	while(al['n'-'a']>=3&&al['e'-'a']>=3&&al['t'-'a']>=1&&al['i'-'a']>=1)
	{
		al['n'-'a']-=2;
		al['e'-'a']-=3;
		al['i'-'a']--;
		al['t'-'a']--;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
