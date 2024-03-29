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
#define MAXN 1000000

typedef long long ll;
using namespace std;

typedef int state[9];
int fact[9];
int dist[MAXN];
state q[MAXN];
int dx[]={ -1, 1, 0, 0 };
int dy[]={  0, 0,-1, 1 };

int hash1(state& st)
{
	int ha=0;
	for(int i=0;i<9;i++)
	{
		int cnt=0;
		for(int j=i+1;j<9;j++)
			if(st[j]<st[i])
				cnt++;
		ha+=fact[8-i]*cnt;
	}
	return ha;
}

void bfs()
{
	fact[0]=1;
	for(int i=1;i<9;i++)
		fact[i]=fact[i-1]*i;
	for(int i=0;i<MAXN;i++)
		dist[i]=-1;
	int front=1,rear=2;
	int ori[9]={ 1,2,3,4,5,6,7,8,0 };
	dist[hash1(ori)]=0;
//	cout<<hash1(ori);
//	cout<<hash(ori)<<endl;
	state &t=q[1];
	memcpy(&t,&ori,sizeof(ori));
/*	for(int i=0;i<9;i++)
		cout<<q[1][i]<<' ';
	cout<<endl;*/
	while(front<rear)
	{
	//	cout<<-1<<endl;
		state& now=q[front];
/*		for(int i=0;i<9;i++)
			cout<<now[i]<<' ';
		cout<<endl;*/
		int h1=hash1(now);
		int z;
		for(z=0;z<9;z++)
			if(!now[z])
				break;
		int x=z/3,y=z%3;
	//	cout<<x<<'|'<<y<<endl;
		for(int d=0;d<4;d++)
		{
			int newx=x+dx[d];
			int newy=y+dy[d];
			int newz=newx*3+newy;
			if(newx>=0&&newx<3&&newy>=0&&newy<3)
			{
				state& temp=q[rear];
				memcpy(&temp,&now,sizeof(now));
				temp[newz]=now[z];
				temp[z]=now[newz];
				int h2=hash1(temp);
				if(dist[h2]!=-1)
					continue;
				else
				{
					rear++;
//					if(h2=45507)
//						cout<<dist[h2]<<endl;
					dist[h2]=dist[h1]+1;
				}
			}
		}
		front++;
	}
//	cout<<cnt<<endl;
}

int main()
{
	string s;
	bfs();
//	for(int i=0;i<100;i++)
	//	cout<<dist[46088]<<endl;
	while(getline(cin,s))
	{
		state st;
		int k=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]>='1'&&s[i]<='9')
			{
				st[k++]=s[i]-'0';
			}
			else if(s[i]=='x')
				st[k++]=0;
		}
		if(dist[hash1(st)]==-1)
			cout<<"unsolvable"<<endl;
		else
			cout<<dist[hash1(st)]<<endl;
	}
	return 0;
}
