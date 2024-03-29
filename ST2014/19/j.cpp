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

inline int compare(string str1, string str2)
{
      if(str1.size() > str2.size()) //长度长的整数大于长度小的整数
            return 1;
      else if(str1.size() < str2.size())
            return -1;
      else
            return str1.compare(str2); //若长度相等，从头到尾按位比较，compare函数：相等返回0，大于返回1，小于返回－1
}
//高精度加法
string ADD_INT(string str1, string str2)
{
      string MINUS_INT(string str1, string str2);
      int sign = 1; //sign 为符号位
      string str;
      if(str1[0] == '-') {
           if(str2[0] == '-') {
                 sign = -1;
                 str = ADD_INT(str1.erase(0, 1), str2.erase(0, 1));
           }else {
                 str = MINUS_INT(str2, str1.erase(0, 1));
           }
      }else {
           if(str2[0] == '-')
                 str = MINUS_INT(str1, str2.erase(0, 1));
           else {
                 //把两个整数对齐，短整数前面加0补齐
                 string::size_type l1, l2;
                 int i;
                 l1 = str1.size(); l2 = str2.size();
                 if(l1 < l2) {
                       for(i = 1; i <= l2 - l1; i++)
                       str1 = "0" + str1;
                 }else {
                       for(i = 1; i <= l1 - l2; i++)
                       str2 = "0" + str2;
                 }
                 int int1 = 0, int2 = 0; //int2 记录进位
                 for(i = str1.size() - 1; i >= 0; i--) { 
                       int1 = (int(str1[i]) - 48 + int(str2[i]) - 48 + int2) % 10;  //48 为 '0' 的ASCII 码
                       int2 = (int(str1[i]) - 48 + int(str2[i]) - 48 +int2) / 10; 
                       str = char(int1 + 48) + str;
                 }
                 if(int2 != 0) str = char(int2 + 48) + str;
          }
     }
     //运算后处理符号位
     if((sign == -1) && (str[0] != '0'))
          str = "-" + str;
     return str;
}


//高精度减法
string MINUS_INT(string str1, string str2)
{
     string MULTIPLY_INT(string str1, string str2);
     int sign = 1; //sign 为符号位
     string str;
     if(str2[0] == '-')
            str = ADD_INT(str1, str2.erase(0, 1));
     else {
            int res = compare(str1, str2);
            if(res == 0) return "0";
            if(res < 0) {
                  sign = -1;
                  string temp = str1;
                  str1 = str2;
                  str2 = temp;
            }
            string::size_type tempint;
            tempint = str1.size() - str2.size();
            for(int i = str2.size() - 1; i >= 0; i--) {
                 if(str1[i + tempint] < str2[i]) {
                       str1[i + tempint - 1] = char(int(str1[i + tempint - 1]) - 1);
                       str = char(str1[i + tempint] - str2[i] + 58) + str;
                 }
                 else
                       str = char(str1[i + tempint] - str2[i] + 48) + str;
            }
           for(int i = tempint - 1; i >= 0; i--)
                str = str1[i] + str;
     } 
     //去除结果中多余的前导0
     str.erase(0, str.find_first_not_of('0'));
     if(str.empty()) str = "0";
     if((sign == -1) && (str[0] != '0'))
          str = "-" + str;
     return str;
}

//高精度乘法
string MULTIPLY_INT(string str1, string str2)
{
     int sign = 1; //sign 为符号位
     string str;
     if(str1[0] == '-') {
           sign *= -1;
           str1 = str1.erase(0, 1);
     }
     if(str2[0] == '-') {
           sign *= -1;
           str2 = str2.erase(0, 1);
     }
     int i, j;
     string::size_type l1, l2;
     l1 = str1.size(); l2 = str2.size();
     for(i = l2 - 1; i >= 0; i --) {  //实现手工乘法
           string tempstr;
           int int1 = 0, int2 = 0, int3 = int(str2[i]) - 48;
           if(int3 != 0) {
                  for(j = 1; j <= (int)(l2 - 1 - i); j++)
                        tempstr = "0" + tempstr;
                  for(j = l1 - 1; j >= 0; j--) {
                        int1 = (int3 * (int(str1[j]) - 48) + int2) % 10;
                        int2 = (int3 * (int(str1[j]) - 48) + int2) / 10;
                        tempstr = char(int1 + 48) + tempstr;
                  }
                  if(int2 != 0) tempstr = char(int2 + 48) + tempstr;
           }
           str = ADD_INT(str, tempstr);
     }
     //去除结果中的前导0
     str.erase(0, str.find_first_not_of('0'));
     if(str.empty()) str = "0";
     if((sign == -1) && (str[0] != '0'))
           str = "-" + str;
     return str;
}
//高精度除法
string DIVIDE_INT(string str1, string str2, int flag)
{
     //flag = 1时,返回商; flag = 0时,返回余数
     string quotient, residue; //定义商和余数
     int sign1 = 1, sign2 = 1;
     if(str2 == "0") {  //判断除数是否为0
           quotient = "ERROR!";
           residue = "ERROR!";
           if(flag == 1) return quotient;
           else return residue;
     }
     if(str1 == "0") { //判断被除数是否为0
           quotient = "0";
           residue = "0";
     }
     if(str1[0] == '-') {
           str1 = str1.erase(0, 1);
           sign1 *= -1;
           sign2 = -1;
     }
     if(str2[0] == '-') {
           str2 = str2.erase(0, 1);
           sign1 *= -1;
     }
     int res = compare(str1, str2);
     if(res < 0) {
           quotient = "0";
           residue = str1;
     }else if(res == 0) {
           quotient = "1";
           residue = "0";
     }else {
           string::size_type l1, l2;
           l1 = str1.size(); l2 = str2.size();
           string tempstr;
           tempstr.append(str1, 0, l2 - 1);
           //模拟手工除法
           for(int i = l2 - 1; i < l1; i++) {
                 tempstr = tempstr + str1[i];
                 for(char ch = '9'; ch >= '0'; ch --) { //试商
                       string str;
                       str = str + ch;
                       if(compare(MULTIPLY_INT(str2, str), tempstr) <= 0) {
                              quotient = quotient + ch;
                              tempstr = MINUS_INT(tempstr, MULTIPLY_INT(str2, str));
                              break;
                       }
                 }
           }
           residue = tempstr;
     }
     //去除结果中的前导0
     quotient.erase(0, quotient.find_first_not_of('0'));
     if(quotient.empty()) quotient = "0";
     if((sign1 == -1) && (quotient[0] != '0'))
     quotient = "-" + quotient;
     if((sign2 == -1) && (residue[0] != '0'))
     residue = "-" + residue;
     if(flag == 1) return quotient;
     else return residue;
}

//高精度除法,返回商
string DIV_INT(string str1, string str2)
{ 
      return DIVIDE_INT(str1, str2, 1);
}
//高精度除法,返回余数
string MOD_INT(string str1, string str2)
{
      return DIVIDE_INT(str1, str2, 0);
}

string gcd(string a,string b){
	if(b=="0")
		return a;
	else
		return gcd(b,MOD_INT(a,b));
}

string extgcd(string a,string b,string &x,string &y){
	string d=a;
	if(b!="0"){
		d=extgcd(b,MOD_INT(a,b),y,x);
	//	y-=(a/b)*x;
		y=MINUS_INT(y,MULTIPLY_INT(DIV_INT(a,b),x));
	}else{
		x="1";y="0";
	}
	return d;
}

int main(){
	string a,b,c;
	while(1){
		cin>>a>>b>>c;
		if(a=="0"&&b=="0"){
			if(c!="0"){
				printf("Unquibable!\n");
				continue;
			}
			else
				break;
		}else if(a=="0"){
			if(MOD_INT(c,b)!="0"){
				printf("Unquibable!\n");
			}else{
				if(DIV_INT(c,b)=="1")
					cout<<0<<" fooms and "<<1<<" foob for a twob!\n";
				else
					cout<<0<<" fooms and "<<DIV_INT(c,b)<<" foobs for a twob!\n";
			}
			continue;
		}else if(b=="0"){
			if(MOD_INT(c,a)!="0"){
				printf("Unquibable!\n");
			}else{
				if(DIV_INT(c,a)=="1")
					cout<<1<<" foom and "<<0<<" foobs for a twob!\n";
				else
					cout<<DIV_INT(c,a)<<" fooms and "<<0<<" foobs for a twob!\n";
			}
			continue;
		}
		string x0,y0,d;
		d=extgcd(a,b,x0,y0);
		cout<<d<<endl;
		cout<<MOD_INT("100","2")<<'!'<<endl;
		if(MOD_INT(c,d)!="0"){
			printf("Unquibable!\n");
			continue;
		}
		x0=MULTIPLY_INT(DIV_INT(c,d),x0);
		y0=MULTIPLY_INT(DIV_INT(c,d),y0);
//		cout<<x0<<' '<<y0<<' '<<d<<endl;
		string bg=DIV_INT(b,d),ag=DIV_INT(a,d);
//		ll lb=-x0*d/b,ub=y0*d/a;
		string lb,ub;
		if(MOD_INT(MULTIPLY_INT(x0,d),b)=="0")
			lb=MULTIPLY_INT(DIV_INT(MULTIPLY_INT(x0,d),b),"-1");
		else if(compare(x0,"0")>0)
			lb=MULTIPLY_INT(DIV_INT(MULTIPLY_INT(x0,d),b),"-1");
		else if(compare(x0,"0")<0)
			lb=ADD_INT(MULTIPLY_INT(DIV_INT(MULTIPLY_INT(x0,d),b),"-1"),"1");
		else
			lb="0";
		if(MOD_INT(MULTIPLY_INT(y0,d),a)=="0")
			ub=DIV_INT(MULTIPLY_INT(y0,d),a);
		else if(compare(y0,0)>0)
			ub=DIV_INT(MULTIPLY_INT(y0,d),a);
		else if(compare(y0,0)<0)
			ub=ADD_INT(DIV_INT(MULTIPLY_INT(y0,d),a),"-1");
		if(((compare(ADD_INT(MULTIPLY_INT(bg,lb),x0),0)<0||compare(ADD_INT(MULTIPLY_INT(MULTIPLY_INT(ag,lb),"-1"),y0),0)<0)&&(compare(ADD_INT(MULTIPLY_INT(bg,ub),x0),0)<0||compare(ADD_INT(MULTIPLY_INT(MULTIPLY_INT(ag,ub),"-1"),y0),0)<0))||compare(ub,lb)<0){
			printf("Unquibable!\n");
			continue;
		}
		string t;
		if(compare(bg,ag)>0){
			t=lb;
		}else if(compare(bg,ag)<0)
			t=ub;
		else
			t="0";
//		cout<<lb<<" | "<<ub<<endl;
//		cout<<t<<'!'<<endl;
//		cout<<x0+bg*t<<" fooms and "<<y0-ag*t<<" foobs for a twob!"<<endl;
		string x,y;
		x=ADD_INT(MULTIPLY_INT(bg,t),x0);
		y=MINUS_INT(y0,MULTIPLY_INT(ag,t));
		if(x=="1"&&y=="1"){
			cout<<1<<" foom and "<<1<<" foob for a twob!\n";
		}else if(x=="1")
			cout<<1<<" foom and "<<y<<" foobs for a twob!\n";
		else if(y=="1")
			cout<<x<<" fooms and "<<1<<" foob for a twob!\n";
		else
			cout<<x<<" fooms and "<<y<<" foobs for a twob!\n";
	}
	return 0;
}
