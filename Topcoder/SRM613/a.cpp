#include<string>
using namespace std;
char al[27];
class TaroString
{
	public:
		string getAnswer(string S)
		{
			for(int i=0;i<S.size();i++)
				al[S[i]-'A']++;
			if(al[0]==1&&al[2]==1&&al[8]==1)
				if(S.find('C')<S.find('A')&&S.find('A')<S.find('I'))
					return "Possible";
			return "Impossible";
		}
};
