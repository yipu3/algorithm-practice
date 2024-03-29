#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<sstream>
#include<string>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

// Point
struct Point{
	double x,y;
	//constructor
	Point(double x=0,double y=0):x(x),y(y){

	}
};
typedef Point Vector;

double Cross(Vector A,Vector B){
	return A.x*B.y-A.y*B.x;
}

Point p[50005];
double aa[50005];

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%lf%lf",&p[i].x,&p[i].y);
	double area=0;
	for(int i=0;i<n-1;i++){
		area+=Cross(p[i],p[i+1]);
		aa[i]=area;
	}
	double all=fabs(aa[n-2]+Cross(p[n-1],p[0]))/2;
	while(k--){
		int a,b;
		scanf("%d%d",&a,&b);
		double tmp;
		if(a-1<0)
			tmp=aa[b-1]-0;
		else
			tmp=aa[b-1]-aa[a-1];
		tmp+=Cross(p[b],p[a]);
		tmp=fabs(tmp)/2;
		double s1=tmp;
		double s2=all-s1;
	//	cout<<s1<<' '<<s2<<endl;
		printf("%.1f\n",min(s1,s2));
	}
	return 0;
}
