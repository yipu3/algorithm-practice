#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#define maxn 1000001
using namespace std;
int isC[maxn];
int ac[maxn],tac[maxn];
char alph[maxn],talph[maxn];
bool vis[30];
using namespace std;
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	getchar();
	string temp;
	for(int i=0;i<k-1;i++)
	{
		getline(cin,temp);
		int n1=temp.find(' ');
		if(temp.find("Captain_Chen")!=-1)
			isC[i]=1;
		if(temp[n1+3]=='A')
			ac[i]=1;
		alph[i]=temp[n1+1];
	}
	getline(cin,temp);
	/*if(temp.find("Captain_Chen")!=-1)
		isC[k-1]=1;
	for(int i=0;i<k;i++)
		printf("%d ",isC[i]);
	printf("\n");
	for(int i=0;i<k;i++)
		printf("%d ",ac[i]);
	printf("\n");*/
	//for(int i=0;i<k;i++)
	//	printf("%c ",alph[i]);
	//printf("\n");
	int ans=0;
	for(int i=0;i<k;i++)
	{
		memcpy(tac,ac,sizeof(ac));
		memcpy(talph,alph,sizeof(alph));
		int cnt=0;
		for(int j=k-1;j>i;j--)
		{
			tac[j]=tac[j-1];
			talph[j]=talph[j-1];
		}
		//for(int e=0;e<k;e++)
		//	printf("%c ",talph[e]);
		//printf("\n");
		tac[i]=0;
		talph[i]=0;
		for(int s=0;s<k;s++)
		{
			if(!vis[talph[s]-'A']&&tac[s]==1)
			{
				vis[talph[s]-'A']=true;
				if(isC[s])
					cnt++;
			}
		}
		if(cnt>ans)
			ans=cnt;
	}
	printf("%d\n",ans);
}
