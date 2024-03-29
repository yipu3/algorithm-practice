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

class RectangleCoveringEasy {
public:
	int solve(int, int, int, int);
};

int RectangleCoveringEasy::solve(int holeH, int holeW, int boardH, int boardW) {
	if(boardH>holeH&&boardW>holeW)
		return 1;
	if(boardW>holeH&&boardH>holeW)
		return 1;
	return 0;
}
