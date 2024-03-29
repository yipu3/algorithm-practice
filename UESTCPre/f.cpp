#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#define maxn 1000005
#define ll long long
using namespace std;
int p[maxn],tp[maxn],judC[maxn],al[maxn],tal[maxn],vis[27];
ll k;
void insert(ll x)
{
	for(ll j=k-1;j>x;j--)
	{
		tp[j]=tp[j-1];
		tal[j]=tal[j-1];
	}
	tp[x]=0;
	tal[x]=0;
}
void copy()
{
	for(ll i=0;i<k;i++)
	{
		tp[i]=p[i];
		tal[i]=al[i];
	}
}
int main()
{
	int n,m;
	int ans=0;
	scanf("%d%d%lld",&n,&m,&k);
	getchar();
	string temp;
	for(ll i=0;i<k;i++)
	{
		getline(cin,temp);
		int n1=temp.find(' ');
		string temp1=temp.substr(0,n1);
		//cout<<temp1<<endl;
		if(temp1=="Captain_Chen")
			judC[i]=1;
		if(i!=k-1)
		{
			if(temp[temp.size()-1]=='C')
				p[i]=1;
			al[i]=temp[n1+1]-'A';
		}
	}
	for(ll i=0;i<k;i++)
	{
		copy();
		insert(i);
		int cnt=0;
		memset(vis,0,sizeof(vis));
		for(ll j=0;j<k;j++)
		{
			if(judC[j]&&tp[j]&&!vis[tal[j]])
			{
				cnt++;
			}
			if(tp[j]&&!vis[tal[j]])
			{
				vis[tal[j]]=1;
			}
		}
		if(cnt>ans)
			ans=cnt;
	}
	printf("%d\n",ans);
}
