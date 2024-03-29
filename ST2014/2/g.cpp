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
	int num,ind;
};

struct tri{
	int a,b,c;
};

vector<tri> tris;
vector<node> a;

bool cmp(const tri &s,const tri &t){
	if(s.a==t.a){
		if(s.b==t.b){
			return s.c<t.c;
		}else
			return s.b<t.b;
	}else
		return s.a<t.a;
}

int main(){
	int p;
	scanf("%d",&p);
	while(p--){
		int k,n;
		scanf("%d%d",&k,&n);
		a.clear();
		tris.clear();
		for(int i=0;i<n;i++){
			int tmp;
			scanf("%d",&tmp);
			node nn;
			nn.num=tmp;
			nn.ind=i;
			a.push_back(nn);
		}
		int sum=0;
		for(int i=0;i<a.size();i++)
			sum+=a[i].num;
		bool flag=false;
		vector<node> tmp;
		int t=1;
		for(;;){
			tmp.clear();
			for(int i=0;i<a.size();i++)
				if(a[i].num>0)
					tmp.push_back(a[i]);
			if(tmp.size()==0){
				flag=true;
				break;
			}else if(tmp.size()==3){
				bool f=true;
				for(int i=0;i<tmp.size();i++)
					if(tmp[i].num!=1){
						f=false;
						break;
					}
				if(f==false){
					flag=false;
					break;
				}else{
					int cc[3];
					for(int i=0;i<tmp.size();i++)
						cc[i]=tmp[i].ind;
					sort(cc,cc+3);
					tri nn;
					nn.a=cc[0];nn.b=cc[1];nn.c=cc[2];
					tris.push_back(nn);
					flag=true;
					break;
				}
			}else if(tmp.size()==1||tmp.size()==2){
				flag=false;
				break;
			}
			a=tmp;
//			cout<<t++<<':'<<endl;
			int nx=tmp.size();
			for(int i=0;i<a.size();i++)
				if(a[i].num==1){
					tmp[i].num--;
					tmp[(nx+i-1)%nx].num--;
					tmp[(i+1)%nx].num--;
					tri nn;
					nn.a=min(a[i].ind,min(a[(nx+i-1)%nx].ind,a[(i+1)%nx].ind));
					nn.c=max(a[i].ind,max(a[(nx+i-1)%nx].ind,a[(i+1)%nx].ind));
					nn.b=a[i].ind+a[(nx+i-1)%nx].ind+a[(i+1)%nx].ind-nn.a-nn.c;
					tris.push_back(nn);
				}
			a=tmp;
		}
		if(flag){
			sort(tris.begin(),tris.end(),cmp);
			printf("%d Y\n",k);
			for(int i=0;i<tris.size();i++)
				printf("%d %d %d\n",tris[i].a+1,tris[i].b+1,tris[i].c+1);
		}else{
			printf("%d N\n",k);
		}
	}
	return 0;
}
