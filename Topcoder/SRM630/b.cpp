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
#define INF 10005

using namespace std;

int d[15][15];

class Egalitarianism3Easy {
public:
	int maxCities(int, vector <int>, vector <int>, vector <int>);
};

int Egalitarianism3Easy::maxCities(int n, vector <int> a, vector <int> b, vector <int> len) {	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			d[i][j]=INF;
		d[i][i]=0;
	}
	for(int i=0;i<n-1;i++)
		d[a[i]][b[i]]=d[b[i]][a[i]]=len[i];
	for(int k=0;i<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	int ans=0;
	vector<int> aa;
	for(int i=0;i<(1<<n);i++){
		aa.clear();
		for(int j=0;j<n;j++)
			if(i&(1<<j))
				aa.push_back(j);
		if(aa.size()==1)
			continue;
		else{
			int cnt=0;
			bool flag=true;
			for(int r=0;r<aa.size();r++)
				for(int s=r+1;s<aa.size();s++)
					if(d[aa[r]][aa[s]]!=d[aa[0]][aa[1]])
						flag=false;
			if(flag)
				ans=max(ans,aa.size());
		}
	}
	return ans;
}
