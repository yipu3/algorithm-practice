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

char ch[6]={
	'(',')','[',']','{','}'
};

bool dfs(string s){
	bool find=false;
	for(int i=0;i<s.size();i++){
		if(s[i]=='X'){
			find=true;
			for(int j=0;j<6;j++){
				string tmp=s;
				tmp[i]=ch[j];
				if(dfs(tmp))
					return true;
			}
		}
	}
	if(find==false){
		stack<char> se;
		for(int i=0;i<s.size();i++){
			if(!se.empty()){
				if((se.top()=='('&&s[i]==')')||(se.top()=='['&&s[i]==']')||(se.top()=='{'&&s[i]=='}'))
					se.pop();
				else
					se.push(s[i]);
			}else
				se.push(s[i]);
		}
		if(se.empty())
			return true;
		else
			return false;
	}
	return false;
}

class BracketExpressions {
public:
	string ifPossible(string);
};

string BracketExpressions::ifPossible(string expression) {
	if(dfs(expression))
		return "possible";
	else
		return "impossible";
}
