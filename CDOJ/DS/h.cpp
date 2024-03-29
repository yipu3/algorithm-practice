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

struct cmp
{
	bool operator()(int &a,int &b)
	{
		return a>b;
	}
};

priority_queue<int> q1;//l
priority_queue<int,vector<int>,cmp> q2;//s

int main()
{
	string s;int m=0;
	cin>>m;
	while(cin>>s)
	{
		if(s=="#")
		{
			cout<<m<<endl;
			int s1=q1.size(),s2=q2.size();
			if(s1>s2)
			{
				m=q1.top();
				q1.pop();
			}
			if(s2>=s1)
			{
				m=q2.top();
				q2.pop();
			}
		}
		else
		{
			int temp;
			temp=0;
			if(temp>=m)
				q2.push(temp);
			else
				q1.push(temp);
			int s1=q1.size(),s2=q2.size();
			if(s1-s2>=1)
			{
				q2.push(m);
				m=q1.top();
				q1.pop();
			}
			if(s2-s1>=1)
			{
				q1.push(m);
				m=q2.top();
				q2.pop();
			}
		}
	}
	return 0;
}
