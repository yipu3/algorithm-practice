#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int c[1005][1005];
int main()
{
	string s1;
	string s2;
	while(getline(cin,s1))
	{
		getline(cin,s2);
		memset(c,0,sizeof(c));
		for(int i=1;i<=s1.size();i++)
			for(int j=1;j<=s2.size();j++)
				if(s1[i-1]==s2[j-1])
					c[i][j]=c[i-1][j-1]+1;
				else if(c[i-1][j]>c[i][j-1])
					c[i][j]=c[i-1][j];
				else
					c[i][j]=c[i][j-1];
		cout<<c[s1.size()][s2.size()]<<endl;
	}
	return 0;
}
