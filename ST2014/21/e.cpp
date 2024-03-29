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
//Vector
typedef Point Vector;

//Vector+Vector=Vector
Vector operator + (Vector A,Vector B){
	return Vector(A.x+B.x,A.y+B.y);
}

//Point-Point=Vector or Vector-Vector=Vector
Vector operator - (Point A,Point B){
	return Vector(A.x-B.x,A.y-B.y);
}

//Vector*p=Vector
Vector operator * (Vector A,double p){
	return Vector(A.x*p,A.y*p);
}

//Vector/p=Vector
Vector operator / (Vector A,double p){
	return Vector(A.x/p,A.y/p);
}

//Point comparision
bool operator < (const Point& a,const Point& b){
	if(a.x==b.x){
		return a.y<b.y;
	}else
		return a.x<b.x;
}

//precious
const double eps=1e-10;
int dcmp(double x){
	if(fabs(x)<eps)
		return 0;
	else
		return x<0 ? -1:1;
}

//Point=Point?
bool operator == (const Point& a,const Point& b){
	return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}

double Dot(Vector A,Vector B){
	return A.x*B.x+A.y*B.y;
}

double Length(Vector A){
	return sqrt(Dot(A,A));
}

double Angle(Vector A,Vector B){
	return acos(Dot(A,B)/Length(A)/Length(B));
}

double Cross(Vector A,Vector B){
	return A.x*B.y-A.y*B.x;
}

double Area2(Point A,Point B,Point C){
	return Cross(B-A,C-A);
}

Vector Rotate(Vector A,double rad){
	return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}

//Please ensure that A cannot be 0
Vector Normal(Vector A){
	double L=Length(A);
	return Vector(-A.y/L,A.x/L);
}


//line1:P+vt line2:Q+wt
//Please ensure that two lines has only one common point(cross(v,w)!=0)
Point GetLineIntersection(Point P,Vector v,Point Q,Vector w){
	Vector u=P-Q;
	double t=Cross(w,u)/Cross(v,w);
	return P+v*t;
}

double DistanceToLine(Point P,Point A,Point B){
	Vector v1=B-A,v2=P-A;
	return fabs(Cross(v1,v2))/Length(v1);
}

double DistanceToSegment(Point P,Point A,Point B){
	if(A==B)
		return Length(P-A);
	Vector v1=B-A,v2=P-A,v3=P-B;
	if(dcmp(Dot(v1,v2))<0)
		return Length(v2);
	else if(dcmp(Dot(v1,v3))>0)
		return Length(v3);
	else
		return fabs(Cross(v1,v2))/Length(v1);
}

//不算任一线段的端点
bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2){
	double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1),
		   c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
	return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}

//不包含线段的端点
bool OnSegment(Point p,Point a1,Point a2){
	return dcmp(Cross(a1-p,a2-p))==0&&dcmp(Dot(a1-p,a2-p))<0;
}

struct Circle{
	double x,y,r;
}cc[205];

int main(){
	int n;
	while(~scanf("%d",&n)&&n){
		for(int i=0;i<n;i++)
			scanf("%lf%lf%lf",&cc[i].x,&cc[i].y,&cc[i].r);
		Point o,p;
		double ans=0;
		o.x=0.0;o.y=0.0;
		p.x=0;p.y=500.0;
		double base=acos(-1)*2/1440;
		for(int i=0;i<1440;i++){
			double ta=base*i;
			double tl=0;
			Point tp=Rotate(p,ta);
			for(int j=0;j<n;j++){
				Point tt;
				tt.x=cc[j].x;tt.y=cc[j].y;
				double dis=DistanceToSegment(tt,o,tp);
				if(dis<cc[j].r){
					tl+=sqrt(cc[j].r*cc[j].r-dis*dis)*2;
				}
			}
			if(tl>ans)
				ans=tl;
		}
		printf("%.3f\n",ans);
	}
	return 0;
}
