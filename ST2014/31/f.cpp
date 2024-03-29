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

typedef __int64 ll;
typedef unsigned long long ull;
using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;

mat mul(mat &A,mat &B){
	mat C(A.size(),vec(B[0].size()));
	for(int i=0;i<A.size();i++)
		for(int k=0;k<B.size();k++)
			for(int j=0;j<B[0].size();j++){
				C[i][j]=(C[i][j]+A[i][k]*B[k][j])%6;
			}
	return C;
}

mat pow(mat A,int n){
	mat B(A.size(),vec(A.size()));
	for(int i=0;i<A.size();i++)
		B[i][i]=1;
	while(n>0){
		if(n&1)
			B=mul(B,A);
		A=mul(A,A);
		n>>=1;
	}
	return B;
}

int main(){
	int n,k;
	while(~scanf("%d%d",&n,&k)&&(n||k)){
		mat A(n),B(k);
		for(int i=0;i<n;i++)
			for(int j=0;j<k;j++){
				ll tmp;
				scanf("%d",&tmp);
				A[i].push_back(tmp);
			}
		for(int i=0;i<k;i++)
			for(int j=0;j<n;j++){
				int tmp;
				scanf("%d",&tmp);
				B[i].push_back(tmp);
			}
		mat C=mul(B,A);
		mat M=pow(C,n*n-1);
		M=mul(A,M);
		M=mul(M,B);
		ll sum=0;
		for(int i=0;i<M.size();i++)
			for(int j=0;j<M[i].size();j++)
				sum+=M[i][j];
		printf("%I64d\n",sum);
	}
	return 0;
}
