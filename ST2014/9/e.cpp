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

int ch[26],word[105][26];
vector<string> ans,cur;

int main(){
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		int n,m;
		memset(word,0,sizeof(word));
		cur.clear();
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			string tmp;
			cin>>tmp;
			for(int j=0;j<tmp.size();j++)
				word[i][tmp[j]-'a']++;
			cur.push_back(tmp);
		}
		printf("Case #%d:\n",cas);
		getchar();
		while(m--){
			string s;
			getline(cin,s);
//			cout<<'S'<<s<<endl;
			ans.clear();
			while(1){
				bool found=false;
				for(int i=0;i<s.size();i++)
					if(s[i]==' '){
						found=true;
						string tmp=s.substr(0,i-0);
//						cout<<"tmp:"<<tmp<<endl;
						memset(ch,0,sizeof(ch));
						for(int j=0;j<tmp.size();j++)
							ch[tmp[j]-'a']++;
						for(int j=0;j<n;j++){
							bool flag=true;
							for(int k=0;k<26;k++){
								if(ch[k]!=word[j][k]){
									flag=false;
									break;
								}
							}
							if(flag){
								ans.push_back(cur[j]);
								break;
							}
						}
						s=s.substr(i+1);
						break;
					}
				if(!found){
					memset(ch,0,sizeof(ch));
					for(int i=0;i<s.size();i++)
						ch[s[i]-'a']++;
					for(int j=0;j<n;j++){
						bool flag=true;
						for(int k=0;k<26;k++){
							if(ch[k]!=word[j][k]){
								flag=false;
								break;
							}
						}
						if(flag){
							ans.push_back(cur[j]);
							break;
						}
					}
					break;
				}
			}
			cout<<ans[0];
			for(int i=1;i<ans.size();i++)
				cout<<' '<<ans[i];
			printf("\n");
		}
		
	}
	return 0;
}
