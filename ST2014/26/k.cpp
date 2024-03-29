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

int card[3];

int main(){
	int a,b,c;
	while(~scanf("%d%d%d",&a,&b,&c)&&(a||b||c)){
		card[0]=a,card[1]=b,card[2]=c;
		sort(card,card+3);
		if(a==b&&b==c){
			if(a==13)
				printf("*");
			else
				printf("%d %d %d",a+1,b+1,c+1);
		}else if(card[0]==card[1]){
			card[2]++;
			if(card[2]==14){
				card[0]++;card[1]++;card[2]=1;
				sort(card,card+3);
				printf("%d %d %d",card[0],card[1],card[2]);
			}else
				printf("%d %d %d",card[0],card[1],card[2]);
		}else if(card[1]==card[2]){
			card[0]++;
			if(card[0]==13)
				printf("1 1 1");
			else if(card[0]==card[1]){
				card[0]++;
				sort(card,card+3);
				printf("%d %d %d",card[0],card[1],card[2]);
			}else
				printf("%d %d %d",card[0],card[1],card[2]);
		}else{
			printf("1 1 2");
		}
		printf("\n");
	}
	return 0;
}
