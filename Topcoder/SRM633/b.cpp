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

class Jumping{
	public:
		string ableToGet(int x, int y, vector <int> jumpLengths){
			ll minn=jumpLengths[0];
			ll maxx=jumpLengths[0];
			int n=jumpLengths.size();
			for(int i=1;i<n;i++){
				if(jumpLengths[i]<=maxx&&jumpLengths[i]>=minn)
					minn=0;
				else
					minn=min(abs(jumpLengths[i]-maxx),abs(jumpLengths[i]-minn));
				maxx=maxx+jumpLengths[i];
			}
			if(x*x+y*y<=maxx*maxx&&x*x+y*y>=minn*minn)
				return "Able";
			else
				return "Not able";
		}
};
