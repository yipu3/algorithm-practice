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
	char s[64];int k;
	while(~scanf("%s%d",s,&k)){
		vector<long long> tmp;
		ll a=0;
		for(int i=0;i<strlen(s);i++){
			if(s[i]>='A'&&s[i]<='Z')
				a=a*k+(int)(s[i]-'A')+10;
			else if(s[i]>='a'&&s[i]<='z')
				a=a*k+(int)(s[i]-'a')+10+26;
			else
				a=a*k+(int)(s[i]-'0');
			cout<<a<<endl;
		}
		cout<<"a:"<<a<<endl;
		ll k1=k;
		for(int i=2;;i++){
			if(k1==1)
				break;
			if(k1%i==0){
				tmp.push_back(i);
				while(k1%i==0){
					k1/=i;
				}
			}
		}
		for(int i=0;i<tmp.size();i++)
			cout<<tmp[i]<<' ';
		cout<<endl;
		ll ans=LONG_MAX;
		for(int i=0;i<tmp.size();i++){
			ll ts=a;
			ll tr=tmp[i];
			ll tcnt=0;
			while(ts/tr){
					tcnt+=ts/tr;
					ts/=2;
			}
			ans=min(ans,tcnt);
		}
		cout<<ans<<endl;
	}
	return 0;
}
