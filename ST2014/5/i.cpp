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

int main(){
	int h,w,n;
	scanf("%d%d%d",&h,&w,&n);
	string s;
	int line=0;
	for(int i=0;i<n;i++){
		string tmp;
		cin>>tmp;
		if(tmp.size()+s.size()+1>w&&s.size()!=0){
			line++;
			s=tmp;
		}else{
			if(s.size()==0)
				s=tmp;
			else
				s=s+" "+tmp;
		}
	}
	line++;
	int page=line/h;
	if(line%h!=0)
		page++;
//	cout<<line<<endl;
	printf("%d\n",page);
	return 0;
}
