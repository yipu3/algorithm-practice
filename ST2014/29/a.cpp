#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 100000
using namespace std;
typedef long long ll;
bool isprime[MAXN+5];
ll prime[MAXN+5];
int generate_prime(int n){
	int cnt = 0;
	memset(isprime, true, sizeof(isprime));
	isprime[1] = false;
	for (int i = 1; i <= n; i++){
		if (isprime[i]){
			prime[cnt++] = i;
			for(int j=2*i;j<MAXN;j+=i)
				isprime[j]=false;
		}
	}
	return cnt;
}

int main() { long long n;
	int cnt = generate_prime(MAXN);
	while (scanf("%lld", &n) == 1) {
		int i=0; long long tmp=1;
		while (tmp<=n) {
			while(prime[i]*tmp<=n){
                    tmp=prime[i]*tmp;
			}
			i++;
			if(tmp*prime[i]>n)
				break;
		}
		printf("%lld\n",tmp);
	}
	return 0;
}
