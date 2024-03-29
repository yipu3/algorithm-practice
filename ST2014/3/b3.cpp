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

vector<ll> a;

void print()
{
    int l=(a.size()-1)/2;
//    printf("%lld\n",V[l]);
    if(a.size()%2==1)
    {
        printf("%lld\n",a[l]);
    }
    else
    {
        int r=l+1;
        ll b=a[l]+a[r];
        if(b%2==0) printf("%lld\n",b/2);
        else printf("%.1lf\n",b*0.5);
    }
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		a.clear();
		scanf("%d",&n);
		int cnt=0;
		while(n--){
			char s[10];ll x;
			scanf("%s",s);
			scanf("%lld",&x);
			if(s[0]=='a'){
				std::vector<ll>::iterator it=lower_bound(a.begin(),a.end(),x);
				a.insert(it,x);
				cnt++;
				if(cnt%2==0){
					printf("%g\n",((double)(a[cnt/2]+a[cnt/2-1])/2));
				}else{
					printf("%lld\n",a[cnt/2]);
				}
//				print();
			}else{
			std::vector<ll>::iterator it=lower_bound(a.begin(),a.end(),x);
				if(it==a.end()){
					printf("Wrong!\n");
				}else if((*it)!=x){
					printf("Wrong!\n");
				}else{
					a.erase(it);
					cnt--;
					if(!cnt)
						printf("Empty!\n");
					else{
						if(cnt%2==0){
							printf("%g\n",((double)(a[cnt/2]+a[cnt/2-1])/2));
						}else{
							printf("%lld\n",a[cnt/2]);
						}
//						print();
					}
				}
			}
		}
	}
	return 0;
}
