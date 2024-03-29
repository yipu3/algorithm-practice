/*
ID: firstaw1
PROG: friday
LANG: C++
*/
#include<algorithm>
#include<fstream>
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

typedef long long ll;
using namespace std;

int ans[7],num;

bool isLeap(int x)
{
	if(x%100==0)
	{
		if(x%400==0)
			return true;
		else
			return false;
	}
	else if(x%4==0)
	{
//		if((x/4)%2==0)
			return true;
//		else
//			return false;
	}
	else
		return false;
}

void count(int year)
{
	int t;
	for(int i=1;i<=12;i++)
	{
		t=num+13;
		ans[t%7]++;
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
			num+=31;
		else if(i==2)
		{
			if(isLeap(year))
				num+=29;
			else
				num+=28;
		}
		else
			num+=30;
	}
}

int main()
{
	ifstream fin("friday.in");
	ofstream fout("friday.out");
	int n;
	fin>>n;
	for(int i=1900;i<1900+n;i++)
		count(i);
	fout<<ans[6]<<' '<<ans[0];
	for(int i=1;i<=5;i++)
		fout<<' '<<ans[i];
	fout<<endl;
	return 0;
}
