#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
int k,n;
int box[31][11];
int G[31][31];
int d[31];
stack<int> a;
bool cmp(int i,int j)
{
	for(int k=0;k<n;k++)
		if(box[i][k]<=box[j][k])
			return false;
	return true;
}
int dp(int i)
{
	int &ans=d[i];
	if(ans>0)
		return ans;
	ans=1;
	for(int j=1;j<=k;j++)
		if(G[i][j])
			if(ans<dp(j)+1)
				ans=dp(j)+1;
	return ans;
}
void print_ans(int i)
{
	a.push(i);
	for(int j=1;j<=k;j++)
		if(G[i][j]&&d[i]==d[j]+1)
		{
			print_ans(j);
			break;
		}
}
int main()
{
	while(cin>>k>>n)
	{
		memset(G,0,sizeof(G));
		for(int i=1;i<=k;i++)
			for(int j=0;j<n;j++)
				cin>>box[i][j];
		for(int i=1;i<=k;i++)
			sort(box[i],box[i]+n);
		/*for(int i=0;i<k;i++)
		{
			for(int j=0;j<n;j++)
				cout<<box[i][j]<<' ';
			cout<<endl;
		}*/
		for(int i=1;i<=k;i++)
			for(int j=1;j<=k;j++)
				if(cmp(i,j))
					G[i][j]=1;
		/*for(int i=0;i<k;i++)
		{
			for(int j=0;j<k;j++)
				cout<<G[i][j]<<' ';
			cout<<endl;
		}*/
		memset(d,0,sizeof(d));
		for(int i=1;i<=k;i++)
			dp(i);
		int max=1;
		int temp;
		for(int i=1;i<=k;i++)
			if(max<d[i])
			{
				max=d[i];
				temp=i;
			}
		cout<<max<<endl;
		print_ans(temp);
		while(!a.empty())
		{
			int u=a.top();
			a.pop();
			cout<<u<<' ';
		}
		cout<<endl;
	}
	return 0;
}
