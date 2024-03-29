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

int markl[10005],markr[10005];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		for(int j=tmp;j<tmp+5;j++)
			markl[j]=1;
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		for(int j=tmp;j<tmp+5;j++)
			markr[j]=1;
	}
	for(int i=0;i<10005;i++){
		bool flag=true;
		for(int j=0;j<8;j++){
			if(markl[i+j]||markr[i+j+8]){
				flag=false;
				break;
			}
		}
		if(flag){
			printf("%.9f",i*3.6/20);
			return 0;
		}
	}
	return 0;
}
