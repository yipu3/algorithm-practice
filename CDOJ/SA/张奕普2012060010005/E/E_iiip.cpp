#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

int a[70],vis[70],len,cnt,n;

int cmp(const void *a,const void *b)
{
	return *(int*)b-*(int*)a;
}

int dfs(int num,int now,int st)
{
	int i,temp;
	if(num==cnt)
		return 1;
	if(now==0)
	{
		while(vis[st])
			st++;
		vis[st]=1;
		if(a[st]==len)
		{
			if(dfs(num+1,0,0))
				return 1;
			else
			{
				vis[st]=0;
				return 0;
			}
		}
		else
		{
			if(dfs(num,a[st],st+1))
				return 1;
			else
			{
				vis[st]=0;
				return 0;
			}
		}
	}
	for(i=st;i<n;i++)
	{
		if(i>0 && !vis[i-1] && a[i]==a[i-1])
			continue;
		if(vis[i])
			continue;
		temp=now+a[i];
	    if(temp==len)
		{
			vis[i]=1;
			if(dfs(num+1,0,0))
				return 1;
			else
			{
				vis[i]=0;
				return 0;
			}
		}
		else if(temp<len)
		{
			vis[i]=1;
			if(dfs(num,temp,i+1))
				return 1;
			vis[i]=0;
		}
	}
	return 0;
}

int main()
{
	while(~scanf("%d",&n) && n)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		qsort(a,n,sizeof(int),cmp);
		for(len=a[0];len<=sum/2;len++)
		{
			if(sum%len==0)
			{
				cnt=sum/len;
				for(int i=0;i<n;i++)
					vis[i]=0;
				if(dfs(0,0,0))
					break;
			}
		}
		if(len==sum/2+1)
			len=sum;
		printf("%d\n",len);
	}
	return 0;
}
