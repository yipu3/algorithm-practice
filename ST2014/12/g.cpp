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

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b,c;
		char aa,bb;
		scanf("%d %c %d %c %d",&a,&aa,&b,&bb,&c);
		int t1;
		if(bb=='*'||bb=='/'||bb=='%'){
			if(aa=='*'||aa=='/'||aa=='%'){
				if(aa=='*'){
					t1=a*b;
					if(bb=='*'){
						t1=t1*c;
					}else if(bb=='/'){
						t1=t1/c;
					}else
						t1=t1%c;
				}else if(aa=='/'){
					t1=a/b;
					if(bb=='*'){
						t1=t1*c;
					}else if(bb=='/'){
						t1=t1/c;
					}else
						t1=t1%c;
				}else{
					t1=a%b;
					if(bb=='*'){
						t1=t1*c;
					}else if(bb=='/'){
						t1=t1/c;
					}else
						t1=t1%c;
				}
			}else{
				if(aa=='+'){
					if(bb=='*'){
						t1=b*c;
					}else if(bb=='/'){
						t1=b/c;
					}else
						t1=b%c;
					t1=t1+a;
				}else if(aa=='-'){
					if(bb=='*'){
						t1=b*c;
					}else if(bb=='/'){
						t1=b/c;
					}else
						t1=b%c;
					t1=a-t1;
				}
			}
		}else{
			if(aa=='*')
				t1=a*b;
			else if(aa=='/')
				t1=a/b;
			else if(aa=='%')
				t1=a%b;
			else if(aa=='-')
				t1=a-b;
			else
				t1=a+b;
			if(bb=='*')
				t1=t1*c;
			else if(bb=='/')
				t1=t1/c;
			else if(bb=='%')
				t1=t1%c;
			else if(bb=='-')
				t1=t1-c;
			else
				t1=t1+c;
		}
		printf("%d\n",t1);
	}
	return 0;
}
