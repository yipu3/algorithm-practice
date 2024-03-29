#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<sstream>
#include<vector>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<cmath>
#include<map>
#include<set>

typedef long long ll;
using namespace std;

string dp[55][55];

class MergeStrings
{
		public:
		string getmin(string S, string A, string B)
		{
				int lena=A.size();
				int lenb=B.size();
				for(int i=0;i<=lena;i++)
						for(int j=0;j<=lenb;j++)
								dp[i][j]="";
				for(int i=0;i<=lena;i++)
						for(int j=0;j<=lenb;j++)
						{
								if(i+j!=dp[i][j].size())
										continue;
								if(A[i]==S[i+j]||S[i+j]=='?')
										dp[i+1][j]=dp[i][j]+A[i];
								if(B[j]==S[i+j]||S[i+j]=='?')
										dp[i][j+1]=dp[i][j]+B[j];
						}
				return dp[lena-1][lenb-1];
		}
};
