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

int oneb(string s){
	if(s=="one")
		return 1;
	if(s=="two")
		return 2;
	if(s=="three")
		return 3;
	if(s=="four")
		return 4;
	if(s=="five")
		return 5;
	if(s=="six")
		return 6;
	if(s=="seven")
		return 7;
	if(s=="eight")
		return 8;
	if(s=="nine")
		return 9;
	return 0;
}

int twob(string s){
	if(s=="ten")
		return 10;
	if(s=="eleven")
		return 11;
	if(s=="twelve")
		return 12;
	if(s=="thirteen")
		return 13;
	if(s=="fourteen")
		return 14;
	if(s=="fifteen")
		return 15;
	if(s=="sixteen")
		return 16;
	if(s=="seventeen")
		return 17;
	if(s=="eighteen")
		return 18;
	if(s=="nineteen")
		return 19;
	if(s=="twenty")
		return 20;
	if(s=="thirty")
		return 30;
	if(s=="forty")
		return 40;
	if(s=="fifty")
		return 50;
	if(s=="sixty")
		return 60;
	if(s=="seventy")
		return 70;
	if(s=="eighty")
		return 80;
	if(s=="ninety")
		return 90;
	return 0;
}

int treeb(string s){
//	cout<<"s:"<<s<<endl;
	int ret=0;
	if(s.find(" hundred")!=-1){
		int tmp=s.find(" hundred");
		string s1=s.substr(0,tmp-0);
//		cout<<s1<<'!'<<endl;
		ret+=oneb(s1)*100;
		if(s.size()==s1.size()){
			return ret;
		}else
			s=s.substr(tmp+8);
//		cout<<"h:"<<s<<' '<<ret<<endl;
	}
	if(s.find("and")!=-1){
		s=s.substr(s.find("and")+4);
//		cout<<"and:"<<s<<endl;
	}
	if(s.find("ty")!=-1){
		string s1=s.substr(0,s.find("ty")+2-0);
		ret+=twob(s1);
		s=s.substr(s.find("ty")+2);
		if(s.size()!=0){
			s=s.substr(1);
			ret+=oneb(s);
		}
	}else{
		if(oneb(s)!=0){
			ret+=oneb(s);
		}else if(twob(s)!=0){
			ret+=twob(s);
		}
	}
	return ret;
}

int main(){
	int t;
	scanf("%d",&t);
	getchar();
	while(t--){
		string s;
		getline(cin,s);
		if(s=="zero"){
			printf("0\n");
			continue;
		}
		int ans=0;
		if(s.find(" million")!=-1){
			int tmp=s.find(" million");
			string s1=s.substr(0,tmp-0);
			ans+=treeb(s1)*1000000;
			s=s.substr(tmp+8);
			if(s.size()==0){
				printf("%d\n",ans);
				continue;
			}else if(s[0]==' '){
				s=s.substr(1);
			}
		}
//		cout<<"1:"<<s<<endl;
		if(s.find(" thousand")!=-1){
			int tmp=s.find(" thousand");
			string s1=s.substr(0,tmp-0);
			ans+=treeb(s1)*1000;
			s=s.substr(tmp+9);
			if(s.size()==0){
				printf("%d\n",ans);
				continue;
			}else if(s[0]=' ')
				s=s.substr(1);
		}
//		cout<<"2:"<<s<<endl;
		ans+=treeb(s);
		printf("%d\n",ans);
	}
	return 0;
}
