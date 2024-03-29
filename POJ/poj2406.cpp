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
#define MAXN 1000005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

char str[MAXN];
int f[MAXN];

int main(){
	while(~scanf("%s",str)){
		int len=strlen(str);
		if(len==1&&str[0]=='.')
			break;
		f[0]=f[1]=0;
		for(int i=1;i<len;i++){
			int j=f[i];
			while(j&&str[i]!=str[j])
				j=f[j];
			f[i+1]=(str[i]==str[j]?j+1:0);
		}
		if(len%(len-f[len])==0)
			printf("%d\n",len/(len-f[len]));
		else
			printf("1\n");
	}
	return 0;
}
