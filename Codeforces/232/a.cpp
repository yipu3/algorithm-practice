#include<cstdio>
#include<cstring>
int main()
{
	int d[110];
	memset(d,0,sizeof(d));
	int n;
	int a,b;
	scanf("%d",&n);
	scanf("%d%d",&a,&b);
	n--;
	while(n--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		for(int i=x;i<y;i++)
			d[i]=1;	
	}
	int cnt=0;
	for(int i=a;i<b;i++)
		if(d[i]==0)
			cnt++;
	printf("%d",cnt);
	return 0;
}
