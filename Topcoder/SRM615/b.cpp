#include<string>
using namespace std;
class LongLongTripDiv2
{
	public:
	string isAble(long long D,int T,int B)
	{
		long long step;
		step=D/B+D%B;
		if(T<step)
			return "Impossible";
		if(T==step)
			return "Possible";
		if(((T-step)%(B-1))==0)
			return "Possible";
		return "Impossible";
	}
};
