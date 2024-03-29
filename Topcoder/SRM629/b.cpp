#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const double eps=1e-9;

double a,b,c;

double f(double x){
	return a*x*x+b*x+c;
}

class CandyMaking {
public:
	double findSuitableDensity(vector <int>, vector <int>);
};


double CandyMaking::findSuitableDensity(vector <int> containerVolume, vector <int> desiredWeight) {	
	int n=containerVolume.size();
	double maxx=0.0;
	for(int i=0;i<n;i++){
		maxx=max(maxx,(double)desiredWeight[i]);
		a+=containerVolume[i]*containerVolume[i];
		b-=2*containerVolume[i]*desiredWeight[i];
		c+=desiredWeight[i]*desiredWeight[i];
	}
	double l=0,r=maxx;
	cout<<maxx<<endl;
	while(r-l>eps){
		double m1=l+(r-l)/3;
		double m2=r-(r-l)/3;
		if(f(m1)<f(m2))
			r=m2;
		else
			l=m1;
	}
	cout<<l<<endl;
	double avg=l;
	double diff=0.0;
	for(int i=0;i<n;i++){
		diff+=abs((double)desiredWeight[i]-(double)containerVolume[i]*avg);
	}
	return diff;
}

