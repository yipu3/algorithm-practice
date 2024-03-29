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

class SquareDivisor {
public:
	long long biggest(long long);
};

long long SquareDivisor::biggest(long long n) {
	long long ans=0;
	for(long long i=1;i<=min(n,1000000LL);i++){
		if(n%i==0){
			long long tmp=n/i;
			if(floor(sqrt(tmp))*floor(sqrt(tmp))==tmp&&tmp>ans)
				ans=tmp;
		}
	}
	for(long long i=1;i<=min(n,1000000LL);i++){
		if(n%(i*i)==0){
			if(i*i>ans)
				ans=i*i;
		}
	}
	return ans;
}
