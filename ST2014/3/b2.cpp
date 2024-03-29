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
#define MAXN 10200

typedef long long ll;
using namespace std;

int c[MAXN],num[MAXN],numt[MAXN],opt[MAXN];
map<int,int> mapp,mapp2;

int lowbit(int x){
	return x&(-x);
}

void add(int x,int d){
	while(x<=MAXN){
		c[x]+=d;
		x+=lowbit(x);
	}
}

int sum(int x){
	int ret;
	while(x>0){
		ret+=c[x];
		x-=lowbit(x);
	}
	return ret;
}

int find_k(int k){
	int ans=0,cnt=0;
	for(int i=20;i>=0;i--){
		if(ans+(1<<i)<MAXN&&cnt+c[ans+(1<<i)]<k){
			ans+=(1<<i);
			cnt+=c[ans];
		}
	}
	return ans+1;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		char s[10];
		mapp.clear();
		mapp2.clear();
		memset(c,0,sizeof(c));
		for(int i=0;i<n;i++){
			int x;
			scanf("%s%d",s,&x);
			if(s[0]=='a'){
				opt[i]=1;//1:add
				num[i]=x;
			}else{
				opt[i]=2;//2:remove
				num[i]=x;
			}
			mapp[x]=0;
		}
		int cnt=1;
		for(int i=0;i<n;i++){
			numt[i]=num[i];
		}
		sort(numt,numt+n);
		for(int i=0;i<n;i++){
			if(mapp[numt[i]]==0){
				mapp[numt[i]]=cnt;
				mapp2[cnt++]=numt[i];
			}
		}
//		for(int i=1;i<cnt;i++)
//			cout<<mapp2[i]<<' ';
//		cout<<endl;
		cnt=0;
//		for(int i=0;i<n;i++)
//			cout<<opt[i]<<' ';
//		cout<<endl;
		for(int i=0;i<n;i++){
			if(opt[i]==1){//add
				add(mapp[num[i]],1);
				cnt++;
				if(cnt%2==0){
					int t1=find_k(cnt/2);
					int t2=find_k(cnt/2+1);
					ll tmp=(ll)mapp2[t1]+(ll)mapp2[t2];
					if(tmp%2==0)
						printf("%lld\n",tmp/2);
					else
						printf("%.1lf\n",tmp*0.5);
				}else{
					int t1=find_k(cnt/2+1);
					printf("%d\n",mapp2[t1]);
				}
			}else if(opt[i]==2){
				if(sum(mapp[num[i]])-sum(mapp[num[i]]-1)==0){
					printf("Wrong!\n");
				}else{
					add(mapp[num[i]],-1);
					cnt--;
					if(cnt==0)
						printf("Empty!\n");
					else{
						if(cnt%2==0){
							int t1=find_k(cnt/2);
							int t2=find_k(cnt/2+1);
							ll tmp=(ll)mapp2[t1]+(ll)mapp2[t2];
							if(tmp%2==0)
								printf("%lld\n",tmp/2);
							else
								printf("%.1lf\n",tmp*0.5);
						}else{
							int t1=find_k(cnt/2+1);
							printf("%d\n",mapp2[t1]);
						}
					}
				}
			}
		}
	}
	return 0;
}
