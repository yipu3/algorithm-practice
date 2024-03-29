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
using namespace std;

struct node{
	int num,id;
};

queue<node> q;

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		node tmp;
		cin>>tmp.num;
		tmp.id=i+1;
		q.push(tmp);
	}
	while(q.size()!=1){
		node now=q.front();q.pop();
		if(now.num>m){
			now.num-=m;
			q.push(now);
		}
	}
	node ans=q.front();
	cout<<ans.id;
	return 0;
}
