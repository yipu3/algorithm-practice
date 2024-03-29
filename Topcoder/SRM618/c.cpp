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
map<vector<int>,int> vis;
bool dfs(vector<int> a,vector<int> b)
{
	int flag=1;
	for(int i=0;i<a.size();i++)
		if(a[i]!=b[i])
		{
			flag=0;
			break;
		}
	if(flag)
		return true;
	vis[a]=1;
	for(int i=0;i<a.size();i++)
		for(int j=i+1;j<a.size();j++)
			if(a[i]>a[j])
			{
				int temp=a[j];
				a[j]=a[i];
				a[i]=temp;
				if(!vis[a])
					if(dfs(a,b))
						return true;
				a[i]=a[j];
				a[j]=temp;
			}
	return false;
}
class MovingRooksDiv2
{
	public:
		string move(vector <int> Y1, vector <int> Y2)
		{
			if(dfs(Y1,Y2))
				return "Possible";
			return "Impossible";
		}
};
