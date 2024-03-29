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
#define MAXN 2000

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

//多边形有向面积
double PolygonArea(Point *p,int n){
	double area=0;
	for(int i=1;i<n-1;i++)
		area+=Cross(p[i]-p[0],p[i+1]-p[0]);
	area/=2;
	return area;
}

Point pa[MAXN],pb[MAXN];

int main(){
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lf%lf%lf%lf",&pa[i].x,&pa[i].y,&pb[i].x,&pb[i].y);
		Point s;
		scanf("%lf%lf",&s.x,&s.y);
		vector<Point> aa,bb;
		int basecnt=0;
		for(int i=0;i<n;i++){
			if(pa[i]==s)
				basecnt++;
			else if(pb[i]==s)
				basecnt++;
			else if(OnSegment(s,pa[i],pb[i]))
				basecnt++;
			else{
				aa.push_back(pa[i]);
				bb.push_back(pb[i]);
			}
		}
		n=aa.size();
		int ans=basecnt;
		for(int i=0;i<n;i++){
			Point t;
			if(dcmp(s.x-aa[i].x)==0){
				t.x=s.x;
				if(aa[i].y>s.y)
					t.y=10100;
				else
					t.y=-10100;
			}else{
				if(s.x<aa[i].x){
					t.x=10100;
					t.y=(aa[i].y-s.y)/(aa[i].x-s.x)*(t.x-s.x)+s.y;
				}else if(s.x>aa[i].x){
					t.x=-10100;
					t.y=(aa[i].y-s.y)/(aa[i].x-s.x)*(t.x-s.x)+s.y;
				}
			}
			int cnt=basecnt;
			for(int i=0;i<n;i++){
				if(OnSegment(aa[i],s,t)||OnSegment(bb[i],s,t)||SegmentProperIntersection(aa[i],bb[i],s,t)){
					cnt++;
				}
			}
			if(cnt>ans)
				ans=cnt;
		}
		for(int i=0;i<n;i++){
			Point t;
			if(dcmp(s.x-bb[i].x)==0){
				t.x=s.x;
				if(bb[i].y>s.y)
					t.y=10100;
				else
					t.y=-10100;
			}else{
				if(s.x<bb[i].x){
					t.x=10100;
					t.y=(bb[i].y-s.y)/(bb[i].x-s.x)*(t.x-s.x)+s.y;
				}else if(s.x>bb[i].x){
					t.x=-10100;
					t.y=(bb[i].y-s.y)/(bb[i].x-s.x)*(t.x-s.x)+s.y;
				}
			}
			int cnt=basecnt;
			for(int i=0;i<n;i++){
				if(OnSegment(bb[i],s,t)||OnSegment(bb[i],s,t)||SegmentProperIntersection(bb[i],bb[i],s,t)){
					cnt++;
				}
			}
			if(cnt>ans)
				ans=cnt;
		}
		printf("%d",ans);
		if(cas!=t)
			printf("\n");
	}
	return 0;
}
