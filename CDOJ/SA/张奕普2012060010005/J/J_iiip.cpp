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
#define MAXN 10000

typedef int state[9];//0~5:which num.6:stict's pos.7:state.8:steps
typedef long long ll;
using namespace std;

int all[10][6]={
	1,0,0,0,0,0,
	1,1,0,0,0,0,
	1,1,1,0,0,0,
	1,1,1,1,0,0,
	1,1,1,1,1,0,
	1,1,1,1,1,1,
	1,0,0,0,0,1,
	1,1,0,0,0,1,
	1,1,1,0,0,1,
	1,1,1,1,0,1,
};//!!
int vis[6][6][6][6][6][6][6][10];
                       //pos,state
state sto[MAXN];int j=0;
void bfs()
{
//	cout<<1<<endl;
	state q[MAXN];//queue
//	cout<<1<<endl;
	int start[9];
	for(int i=0;i<6;i++)
		start[i]=i;
	start[6]=start[7]=start[8]=0;
	int front=1,rear=2;
	state& f=q[1];
	state& f2=sto[j++];
	memcpy(&f,&start,sizeof(start));
	memcpy(&f2,&start,sizeof(start));
//	for(int i=0;i<9;i++)
//		cout<<q[1][i];
//	cout<<endl;
	vis[start[0]][start[1]][start[2]][start[3]][start[4]][start[5]][start[6]][start[7]]=1;
	while(front<rear)
	{
		state& now=q[front++];
		state t;
		for(int i=0;i<9;i++)
			t[i]=now[i];
		t[8]=now[8]+1;//step
		//right move
		int ns=now[7];
		t[6]++;
		if(t[6]>ns||(t[6]>now[7]-6&&now[7]>5))
		{
			t[7]++;
			if(t[7]==10)
				t[7]=5;
		}
		if(!vis[t[0]][t[1]][t[2]][t[3]][t[4]][t[5]][t[6]][t[7]]&&t[6]<6)//!!
		{
			vis[t[0]][t[1]][t[2]][t[3]][t[4]][t[5]][t[6]][t[7]]=1;
			state& t2=sto[j++];
			state& t3=q[rear++];
		    memcpy(&t2,&t,sizeof(t));
			memcpy(&t3,&t,sizeof(t));
		}
		t[6]--;
		t[7]=now[7];
		//an exchange with the 1st num do not change state.
		int ch=t[0];
		t[0]=t[t[6]];
		t[t[6]]=ch;
		if(!vis[t[0]][t[1]][t[2]][t[3]][t[4]][t[5]][t[6]][t[7]])
		{
			vis[t[0]][t[1]][t[2]][t[3]][t[4]][t[5]][t[6]][t[7]]=1;
			state& t2=sto[j++];
			state& t3=q[rear++];
			memcpy(&t2,&t,sizeof(t));
			memcpy(&t3,&t,sizeof(t));
		}
		ch=t[0];
		t[0]=t[t[6]];
		t[t[6]]=ch;
		//an exchange with the last one
		ch=t[5];
		t[5]=t[t[6]];
		t[t[6]]=ch;
		if(t[7]<5)//impossible to reach state 5
			t[7]+=6;
		if(!vis[t[0]][t[1]][t[2]][t[3]][t[4]][t[5]][t[6]][t[7]])
		{
			vis[t[0]][t[1]][t[2]][t[3]][t[4]][t[5]][t[6]][t[7]]=1;
			state& t2=sto[j++];
			state& t3=q[rear++];
			memcpy(&t2,&t,sizeof(t));
			memcpy(&t3,&t,sizeof(t));
		}
	}
//	cout<<j<<endl;
}

int main()
{
	int s,e,ans;
	bfs();
	while(~scanf("%d%d",&s,&e))
	{
		int m1[6],m2[6];
		for(int i=5;i>=0;i--)
		{
			m1[i]=s%10;s/=10;
			m2[i]=e%10;e/=10;
		}
		ans=INT_MAX;
		for(int i=0;i<j;i++)
		{
			int temp=sto[i][8];
			int flag=1;
			for(int k=0;k<6;k++)
			{
				if(!all[sto[i][7]][k])//hasn't been moved
					if(m1[k]!=m2[k])
					{
						flag=0;
						break;
					}
				temp+=abs(m1[sto[i][k]]-m2[k]);
			}
			if(!flag)
				continue;
			if(temp<ans)
				ans=temp;
		}
		cout<<ans<<endl;
	}
	return 0;
}
