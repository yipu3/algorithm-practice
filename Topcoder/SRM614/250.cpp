#include<string>
#include<iostream>
#include<sstream>
using namespace std;
class MicroStrings
{
	public:string makeMicroString(int A,int D)
	{
		string ans;
		while(A>=0)
		{
			stringstream s;
			s<<A;
			string temp;
			s>>temp;
			ans+=temp;
			A-=D;
		}
		return ans;
	}
};
