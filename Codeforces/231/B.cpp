#include<cstdio>
int a[1000010];
int main()
{
	int p,x;
	scanf("%d%d",&p,&x);
	for(int i=0;i<10;i++)
	{
		int m=0;
		a[0]=i;
		for(int j=1;j<p;j++)
		{
			a[j]=(a[j-1]*x+m)%10;
			m=(a[j-1]*x+m)/10;
		}
		if(a[p-1]!=0&&a[p-1]*x+m==a[0])
		{
			for(int i=p-1;i>=0;i--)
				printf("%d",a[i]);
			printf("\n");
			return 0;
		}
	}
	printf("Impossible\n");
	return 0;
}
