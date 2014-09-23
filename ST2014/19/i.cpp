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

int a[7],b[7];

int main(){
	while(~scanf("%d%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6])){
		bool flag=false;
		for(int i=0;i<=6;i++)
			if(a[i]!=0){
				flag=true;
				break;
			}
		if(!flag)
			break;
		for(int i=0;i<=6;i++)
			b[i]=a[i];
		int ansa=0;
		ansa+=(b[5]+b[6])/30;
		if((b[5]+b[6])%30!=0){
			if(25-(b[5]+b[6])%30<=b[4]&&b[5]>=(b[5]+b[6])%30)
				b[4]-=(25-(b[5]+b[6])%30);
			ansa++;
		}
		ansa+=(b[4]+b[3])/25;
		if((b[4]+b[3])%25!=0){
			if(20-(b[4]+b[3])%25<=b[2]&&b[3]>=(b[4]+b[3])%25)
				b[2]-=(20-(b[4]+b[3])%25);
			ansa++;
		}
		ansa+=(b[0]+b[1]+b[2])/20;
		if((b[0]+b[1]+b[2])%20!=0)
			ansa++;
		int ans=0;
		ans+=(a[0]+a[1]+a[2])/20;
		if((a[0]+a[1]+a[2])%20!=0){
			if(25-(a[0]+a[1]+a[2])%20<=a[3])
				a[3]-=(25-(a[0]+a[1]+a[2])%20);
			ans++;
		}
		ans+=(a[3]+a[4])/25;
		if((a[3]+a[4])%25!=0){
			if(30-(a[3]+a[4])%25<=a[5])
				a[5]-=(30-(a[3]+a[4])%25);
			ans++;
		}
		ans+=(a[5]+a[6])/30;
		if((a[5]+a[6])%30!=0)
			ans++;
	//	cout<<ansa<<' '<<ans<<endl;
		printf("%d\n",min(ans,ansa));
	}
	return 0;
}
