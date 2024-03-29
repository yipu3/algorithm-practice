#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#define MAXN 100000
#define INF 1000000005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

map<int,int> mapi,mapb;
int a[MAXN+3];

struct node{
	int ind,maxx;
}prev[MAXN+3],maxv[MAXN*4+3];

node nl,nr;
stack<int> s;
vector<int> b;

vector<int>::iterator it1;
vector<int>::iterator it2;

int ql,qr;//[ql,qr]
node query(int o,int L,int R){
	int M=L+(R-L)/2;
	if(ql<=L&&qr>=R)
		return maxv[o];
	if(qr<=M)
		return query(o*2,L,M);
	if(ql>M)
		return query(o*2+1,M+1,R);
	else{
		node nl=query(o*2,L,M);
		node nr=query(o*2+1,M+1,R);
		if(nl.maxx>nr.maxx)
			return nl;
		else
			return nr;
	}
}

int p,v,in;//A[p]=v
void update(int o,int L,int R){
	int M=L+(R-L)/2;
	if(L==R){
		maxv[o].maxx=v;
		maxv[o].ind=in;
	}else{
		if(p<=M)
			update(o*2,L,M);
		else update(o*2+1,M+1,R);
		if(maxv[o*2].maxx>maxv[o*2+1].maxx)
			maxv[o]=maxv[o*2];
		else
			maxv[o]=maxv[o*2+1];
	}
}

int main(){
	freopen("financial.in","r",stdin);
	freopen("financial.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	mapi.clear();mapb.clear();
	int minn=INF,maxx=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		minn=min(minn,a[i]);
		maxx=max(maxx,a[i]);
	}
	for(int i=1;i<=n;i++)
		b.push_back(a[i]);
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	for(int i=0;i<b.size();i++){
		mapi[b[i]]=i+1;
		mapb[i+1]=b[i];
	}
	for(int i=0;i<=b.size();i++){
		prev[i].ind=-1;
		prev[i].maxx=0;
	}
	for(int i=0;i<=4*(b.size()+1);i++){
		maxv[i].ind=-1;
		maxv[i].maxx=0;
	}
	for(int i=1;i<=n;i++){
		it1=upper_bound(b.begin(),b.end(),a[i]-k);
		it2=lower_bound(b.begin(),b.end(),a[i]+k);
		p=mapi[a[i]];
		in=p;
		if(a[i]-k<minn&&a[i]+k>maxx){
			v=1;
			prev[p].maxx=1;
			prev[p].ind=-1;
			update(1,1,n);
		}else if(a[i]-k<minn){
			ql=(int)(it2-b.begin())+1,qr=b.size();
			nr=query(1,1,n);
			v=nr.maxx+1;
			if(v==1)
				prev[p].ind=-1;
			else
				prev[p].ind=nr.ind;
			prev[p].maxx=nr.maxx+1;
			update(1,1,n);
		}else if(a[i]+k>maxx){
			ql=1,qr=(int)(it1-b.begin());
			nl=query(1,1,n);
			v=nl.maxx+1;
			if(v==1)
				prev[p].ind=-1;
			else
				prev[p].ind=nl.ind;
			prev[p].maxx=nl.maxx+1;
			update(1,1,n);
		}else{
			ql=(int)(it2-b.begin())+1,qr=b.size();
			nr=query(1,1,n);
			ql=1,qr=(int)(it1-b.begin());
			nl=query(1,1,n);
			if(nl.maxx>nr.maxx){
				v=nl.maxx+1;
				if(v==1)
					prev[p].ind=-1;
				else
					prev[p].ind=nl.ind;
				prev[p].maxx=nl.maxx+1;
				update(1,1,n);
			}else{
				v=nr.maxx+1;
				if(v==1)
					prev[p].ind=-1;
				else
					prev[p].ind=nr.ind;
				prev[p].maxx=nr.maxx+1;
				update(1,1,n);
			}
		}
	}
	maxx=0;
	for(int i=1;i<=b.size();i++)
		maxx=max(prev[i].maxx,maxx);
	printf("%d\n",maxx);
	for(int i=1;i<=b.size();i++){
		if(prev[i].maxx==maxx){
			int tmp=i;
			s.push(tmp);
			int cnt=1;
			while(prev[tmp].ind!=-1){
				tmp=prev[tmp].ind;
				s.push(tmp);
			}
			break;
		}
	}
	printf("%d",mapb[s.top()]);
	s.pop();
	while(!s.empty()){
		printf(" %d",mapb[s.top()]);
		s.pop();
	}
	return 0;
}
