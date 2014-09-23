#include<cstdio>
#include<cmath>
double x[10005],y[10005];
int main()
{
	int n;
	scanf("%d",&n);
	double sx,sy;
	for(int i=0;i<n;i++)
	{
		scanf("%lf%lf",&x[i],&y[i]);
	}
	scanf("%lf%lf",&sx,&sy);
	int ai,aj;
	double d=10;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			double l1=sqrt((sx-x[i])*(sx-x[i])+(sy-y[i])*(sy-y[i]));
			double l2=sqrt((sx-x[j])*(sx-x[j])+(sy-y[j])*(sy-y[j]));
			double td=(((sx-x[i])/l1/l2)*(sx-x[j])+((sy-y[i])/l1/l2)*(sy-y[j]));
			if(td<d)
			{
				ai=i;
				aj=j;
				d=td;
			}
			if(td==d)
			{
				if(sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))<sqrt((x[ai]-x[aj])*(x[ai]-x[aj])+(y[ai]-y[aj])*(y[ai]-y[aj])))
				{
					ai=i;
					aj=j;
				}
			}
		}
	d=0;
	for(int i=ai;i<aj;i++)
		d+=sqrt((x[i+1]-x[i])*(x[i+1]-x[i])+(y[i+1]-y[i])*(y[i+1]-y[i]));
	printf("%.3lf\n",d);
}
