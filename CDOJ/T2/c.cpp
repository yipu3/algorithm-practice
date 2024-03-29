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

int pos[26];
int vis[26];

bool isal(char c)
{
	if(c<='Z'&&c>='A')
		return true;
	if(c<='z'&&c>='a')
		return true;
	return false;
}

string lock(char a,char b)
{
//	cout<<a<<b<<endl;
	if(a=='J')
		a='I';
	if(b=='J')
		b='I';
	int pa=pos[a-'A'];
	int pb=pos[b-'A'];
	if(pa/5==pb/5)
	{
		int na=pa+1;
		int nb=pb+1;
		if(na/5>pa/5)
			na-=5;
		if(nb/5>pa/5)
			nb-=5;
		string temp;
		for(int i=0;i<26;i++)
			if(pos[i]==na&&i!=9)
				temp+=('A'+i);
		for(int i=0;i<26;i++)
			if(pos[i]==nb&&i!=9)
				temp+=('A'+i);
		return temp;
	}
	if(pa%5==pb%5)
	{
		int na=pa+5;
		int nb=pb+5;
		if(na/5>4)
			na=na%5;
		if(nb/5>4)
			nb=nb%5;
		string temp;
		for(int i=0;i<26;i++)
			if(pos[i]==na&&i!=9)
				temp+=('A'+i);
		for(int i=0;i<26;i++)
			if(pos[i]==nb&&i!=9)
				temp+=('A'+i);
		return temp;
	}
	if(pa%5>pb%5)
	{
		int d=pa%5-pb%5;
		int na,nb;
		na=pa-d;
		nb=pb+d;
		string temp;
		for(int i=0;i<26;i++)
			if(pos[i]==na&&i!=9)
				temp+=('A'+i);
		for(int i=0;i<26;i++)
			if(pos[i]==nb&&i!=9)
				temp+=('A'+i);
		return temp;
	}
	else
	{
		int d=pb%5-pa%5;
		int na,nb;
		na=pa+d;
		nb=pb-d;
		string temp;
		for(int i=0;i<26;i++)
			if(pos[i]==na&&i!=9)
				temp+=('A'+i);
		for(int i=0;i<26;i++)
			if(pos[i]==nb&&i!=9)
				temp+=('A'+i);
		return temp;
	}
}

int main()
{
	int n;
	cin>>n;
	getchar();
	for(int cas=1;cas<=n;cas++)
	{
		string s1;
		string s2;
		getline(cin,s1);
		getline(cin,s2);
		memset(vis,0,sizeof(vis));
		memset(pos,-1,sizeof(pos));
		for(int i=0;i<s1.size();i++)
			if(isal(s1[i]))
				s1[i]=toupper(s1[i]);
		for(int i=0;i<s2.size();i++)
			if(isal(s2[i]))
				s2[i]=toupper(s2[i]);
	//	cout<<s1<<endl<<s1.size()<<endl;
	//	cout<<s2<<endl<<s2.size()<<endl;
		memset(vis,0,sizeof(vis));
		memset(pos,-1,sizeof(pos));
		int i,j;
		for(i=0,j=0;i<s1.size();i++)
		{
			if(isal(s1[i]))
				if(!vis[s1[i]-'A'])
				{
					pos[s1[i]-'A']=j;
					vis[s1[i]-'A']=1;
					j++;
				}
		}
		for(int i=0;i<26;i++)
		{
			if(!vis[i]&&('A'+i)!='J')
			{
				pos[i]=j;
				j++;
			}
		}
	//	for(int i=0;i<26;i++)
	//		cout<<pos[i]<<' ';
		string ans;
		vector<char> s3;
		pos['J'-'A']=pos['I'-'A'];
		for(int i=0;i<s2.size();i++)
		{
			if(isal(s2[i]))
				s3.push_back(s2[i]);
		}
		j=0;
		for(int i=0;i<s3.size();)
		{
			
			if(i==s3.size()-1)
			{
				while(('A'+j)==s3[i]||('A'+j)=='J')
					j++;
				j%=26;
				ans+=lock(s3[i],('A'+j));
				j++;
				i++;
				j=j%26;
			}
			else
			{
				if(s3[i]!=s3[i+1])
				{
					ans+=lock(s3[i],s3[i+1]);
					i+=2;
				}
				else
				{
					while(('A'+(j))==s3[i]||('A'+j)=='J')
						j++;
					j%=26;
					ans+=lock(s3[i],('A'+j));
					j++;
					i++;
					j=j%26;
				}
			}
		}
		cout<<"Case "<<cas<<": "<<ans<<endl;
	}
	return 0;
}
