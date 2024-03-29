#include<iostream>
using namespace std;
const long N=200000;
long prime[N]={ 0 },num_prime=0;
int isNotPrime[N]={ 1,1 };
int main()
{
		for(int i=2;i<N;i++)
		{
				if(!isNotPrime[i])
						prime[num_prime++]=i;
				for(long j=0;j<num_prime && i*prime[j]<N;j++)
				{
						isNotPrime[i*prime[j]]=1;
						if(!(i%prime[j]))
								break;
				}
		}
		for(int i=0;i<100;i++)
				cout<<isNotPrime[i]<<' ';
		return 0;
}
