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
typedef long long ll;

class SquareDivisor {
public:
	long long biggest(long long);
};

long long SquareDivisor::biggest(long long n) {
	ll ans;
	for(ll i=1;i*i<=n;i++)
		if(n%(i*i)==0)
			ans=i;
	return ans;
}

