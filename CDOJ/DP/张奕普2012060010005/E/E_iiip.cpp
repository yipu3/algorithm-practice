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
#define MAXN 2010

typedef long long ll;
using namespace std;

int dp[MAXN][MAXN],ap[MAXN],bp[MAXN],as[MAXN],bs[MAXN];

struct node
{
    int num,val;
}q[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,w;
        scanf("%d%d%d",&n,&m,&w);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&ap[i],&bp[i],&as[i],&bs[i]);
        }
/*        for(int i=0;i<MAXN;i++)
			for(int j=0;j<MAXN;j++)
				dp[i][j]=INT_MIN;*/
		memset(dp,128,sizeof(dp));
        for(int i=0;i<w+1;i++)
            for(int j=0;j<=as[i];j++)
                dp[i+1][j]=-j*ap[i];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=m;j++)
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            if(i>w)
			{
        	    int head=1,tail=0;
    	        q[++tail].num=0;
        	    q[tail].val=dp[i-w][0];
         	   //index of q:dp[i-w][k]+k*ap[i]
          	    for(int j=1;j<=m;j++)
     	        {
            	    while(tail>=head&&j-q[head].num>as[i])
            	        head++;
            	    if(tail>=head)
         	            dp[i+1][j]=max(dp[i+1][j],q[head].val-(j-q[head].num)*ap[i]);
              	    while(tail>=head&&q[tail].val+q[tail].num*ap[i]<dp[i-w][j]+j*ap[i])
               	        tail--;
            	    q[++tail].num=j;
             	    q[tail].val=dp[i-w][j];
         	    }
         	    head=1;tail=0;
          	    q[++tail].num=m;
           	    q[tail].val=dp[i-w][m];
           		for(int j=m-1;j>=0;j--)
            	{
                	while(tail>=head&&q[head].num-j>bs[i])
                    	head++;
                	if(tail>=head)
                    	dp[i+1][j]=max(dp[i+1][j],q[head].val+(q[head].num-j)*bp[i]);
                	while(tail>=head&&q[tail].val+q[tail].num*bp[i]<dp[i-w][j]+j*bp[i])
                    	tail--;
                	q[++tail].num=j;
                	q[tail].val=dp[i-w][j];
            	}
			}
        }
/*        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
                cout<<dp[i][j]<<' ';
            cout<<endl;
        }*/
        int ans=0;
        for(int i=0;i<=m;i++)
        {
            ans=max(ans,dp[n][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
