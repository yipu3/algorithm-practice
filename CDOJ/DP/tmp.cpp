#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int INF=0xffffff;
int Map[9][9],Bak[9][9][9][9];
double Sum[16][9][9][9][9];

//返回区域的和的平方
int GetSum(int x1,int y1,int x2,int y2)
{
    int i,j,ret=0;
    for(i=x1;i<=x2;++i)
        for(j=y1;j<=y2;++j)
            ret+=Map[i][j];
    return ret*ret;
}

//记录任何矩形区域的和的平方
void Init()
{
    int i,j,k,l;
    for(i=1;i<=8;++i)
        for(j=1;j<=8;++j)
            for(k=i;k<=8;++k)
                for(l=j;l<=8;++l)
                    Bak[i][j][k][l]=GetSum(i,j,k,l);
    
}

double GetMin(double x,double y)
{
    return x<y?x:y;
}

double DP(int k,int x1,int y1,int x2,int y2)
{
    int i,j;
    if(Sum[k][x1][y1][x2][y2]>=0)
        return Sum[k][x1][y1][x2][y2];
    if(k==1)
        return Bak[x1][y1][x2][y2];
    Sum[k][x1][y1][x2][y2]=INF;
    //进行上下切
    for(i=x1;i<x2;++i)
    {
        Sum[k][x1][y1][x2][y2]=GetMin(Sum[k][x1][y1][x2][y2],
            GetMin(DP(k-1,x1,y1,i,y2)+Bak[i+1][y1][x2][y2],DP(k-1,i+1,y1,x2,y2)+Bak[x1][y1][i][y2]));
    }
    //进行左右切
    for( j=y1; j<y2; ++j )
    {
        Sum[k][x1][y1][x2][y2]=GetMin( Sum[k][x1][y1][x2][y2],
            GetMin(DP(k-1,x1,y1,x2,j)+Bak[x1][j+1][x2][y2],DP(k-1,x1,j+1,x2,y2)+Bak[x1][y1][x2][j])) ;
    }
    return Sum[k][x1][y1][x2][y2];
}

int main()
{
    int i,j,n;
    double ans,all=0;
    cin>>n;
    for(i=1;i<9;++i)
    {
        for(j=1;j<9;++j)
        {
            cin>>Map[i][j];
            all+=Map[i][j];
        }
    }
    Init();
    memset(Sum,-1,sizeof(Sum));
    all/=n;
    DP(n,1,1,8,8);
    ans=sqrt(Sum[n][1][1][8][8]/n-all*all);
    printf("%.3f\n",ans);
    return 0;
}
