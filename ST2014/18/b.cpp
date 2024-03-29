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

struct ant{
	int pos,ind;
};
vector<ant> la,ra;

bool cmpa(const ant &a,const ant &b){
	return a.pos<b.pos;
}

struct node{
	int dis,li,ri;
};
vector<node> d;

bool cmpd(const node &a,const node &b){
	return a.dis<b.dis;
}

int main(){
	int n,l;
	while(~scanf("%d%d",&n,&l)){
		if(n==0&&l==0)
			break;
		la.clear();ra.clear();
		for(int i=0;i<n;i++){
			getchar();
			char c;int pos;
			scanf("%c %d",&c,&pos);
			if(c=='L'){
				ant tmp;
				tmp.pos=pos;
				tmp.ind=i;
				la.push_back(tmp);
			}else{
				ant tmp;
				tmp.pos=pos;
				tmp.ind=i;
				ra.push_back(tmp);
			}
		}
		d.clear();
	//	cout<<la.size()<<' '<<ra.size()<<endl;
	//	for(int i=0;i<la.size();i++)
	//		cout<<la[i].pos<<'!';
	//	cout<<endl;
	//	for(int i=0;i<ra.size();i++)
	//		cout<<ra[i].pos<<'?';
	//	cout<<endl;
		for(int i=0;i<la.size();i++)
			for(int j=0;j<ra.size();j++){
				if(la[i].pos-ra[j].pos>0){
					node tmp;
					tmp.dis=la[i].pos-ra[j].pos;
					tmp.li=i;
					tmp.ri=j;
					d.push_back(tmp);
				}
			}
	//	cout<<d.size()<<'!'<<endl;
	//	for(int i=0;i<d.size();i++)
	//		cout<<d[i].dis<<' '<<d[i].li<<' '<<d[i].ri<<endl;
		sort(d.begin(),d.end(),cmpd);
		for(int i=0;i<d.size();i++){
			if(d[i].dis%2==0){
				int swap=la[d[i].li].ind;
				la[d[i].li].ind=ra[d[i].ri].ind;
				ra[d[i].ri].ind=swap;
			}
		}
		sort(la.begin(),la.end(),cmpa);
		sort(ra.begin(),ra.end(),cmpa);
		int aa=0,bb=0;
		if(la.size()>0)
			aa=la[la.size()-1].pos;
		if(ra.size()>0)
	    	bb=l-ra[0].pos;
		if(bb>aa){
			printf("%d %d\n",bb,ra[0].ind+1);
		}else
			printf("%d %d\n",aa,la[la.size()-1].ind+1);
	}
	return 0;
}
