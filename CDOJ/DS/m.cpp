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
#define MAXN 1000100

typedef long long ll;
using namespace std;

int del[MAXN];
int ans=0;

struct Trie
{
	int ch[MAXN][4];
	int val[MAXN];
	int sz;
	vector<int> path[MAXN];
	Trie()
	{
		sz=1;memset(ch[0],0,sizeof(ch[0]));
	}
	int idx(char c)
	{
		switch(c)
		{
			case 'A':return 0;
			case 'G':return 1;
			case 'C':return 2;
			case 'T':return 3;
		}
	}
	void insert(string s,int v)
	{
		int u=0,n=s.size();
		for(int i=0;i<n;i++)
		{
			int c=idx(s[i]);
			if(!ch[u][c])
			{
				memset(ch[sz],0,sizeof(ch[sz]));
				ch[u][c]=sz++;
			}
			u=ch[u][c];
			val[u]=i+1;
			path[u].push_back(v);
		}
	}
}tree;

vector< pair<int,int> > ret;
void solve(int u)
{
	for(int i=0;i<4;i++)
	{
		int cnt=0;
		vector<int>::iterator temp=tree.path[tree.ch[u][i]].begin();
		for(;temp!=tree.path[tree.ch[u][i]].end();temp++)
			if(!del[*temp])
				cnt++;
		if(cnt>=2)
			solve(tree.ch[u][i]);
	}
	while(1)
	{
		int cnt=0;
		vector<int>::iterator t2=tree.path[u].begin();
		for(;t2!=tree.path[u].end();t2++)
			if(!del[*t2])
				cnt++;
		if(cnt<2)
			break;
		vector<int>::iterator it=tree.path[u].begin();
		int a,b;
		while(del[*it])
			it++;
		a=*it;
		it++;
		while(del[*it])
			it++;
		b=*it;
		del[a]=del[b]=1;
		ans+=tree.val[u];
		ret.push_back(make_pair(a,b));
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		tree.insert(s,i);
	}
	solve(0);
	printf("%d\n",ans);
	for(int i=0;i<ret.size();i++)
	{
		pair<int,int> temp=ret[i];
		printf("%d %d\n",temp.first,temp.second);
	}
	return 0;
}
