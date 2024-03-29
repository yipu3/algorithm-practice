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

string lcs_search(string str1, string str2)
{
    int length = 5001;
    int end = 0;
    if (str1.length() < str2.length())  
    {
        string strTemp = str1;
        str1 = str2;
        str2 = strTemp;
    }   
    int *sign = new int[str1.length()];
    // sign里存储的是母串（str1）每个元素前向能与子串匹配的公共子串数
    // 比如sign[12]==5;则说明从str1[12]往前(所以在第二个for循环中idx1的计数就是从str1的最后一个开始)5个元素(包括[12])，
    // 能与str2的某一段匹配
    for (size_t idx2 = 0; idx2 < str2.length(); idx2++)
    {
        for (int idx1 = str1.length() - 1; idx1 >= 0; idx1--)
        {
            if (str2[idx2] == str1[idx1])
            {
                if (idx2 == 0 || idx1 == 0)                          //idx2==0，则母串的idx1元素必然只能匹配一个，idx1==0同理  
                {
                    sign[idx1] = 1;
                }
                else                                           //由于该次idx1匹配，所以子串可以+1   
                {
                    sign[idx1] = sign[idx1 - 1] + 1;
                }
            }
            else                                               //不匹配，则此位置的sign归零
            {
                sign[idx1] = 0;
            }
            if (sign[idx1] < length)                             //结果存储
            {
                length = sign[idx1];
                end = idx1;
            }
        }
    }
    delete[] sign;   
    return str1.substr(end - length + 1, length);   
}

int main()
{
	string s1,s2,temp;
	int ans=5001;
	cin>>s1>>s2;
	temp=lcs_search(s1,s2);
	ans=temp.size();
	if(ans==0)
		ans=-1;
	cout<<ans<<endl;
	return 0;
}
