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

const int MAXN = 410;

struct bign
{
	int len, s[MAXN];
	bign ()
	{
		memset(s, 0, sizeof(s));
		len = 1;
	}
	bign (int num) { *this = num; }
	bign (const char *num) { *this = num; }
	bign operator = (const int num)
	{
		char s[MAXN];
		sprintf(s, "%d", num);
		*this = s;
		return *this;
	}
	bign operator = (const char *num)
	{
		for(int i = 0; num[i] == '0'; num++) ;  //去前导0
		len = strlen(num);
		for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0';
		return *this;
	}
	bign operator + (const bign &b) const //+
	{
		bign c;
		c.len = 0;
		for(int i = 0, g = 0; g || i < max(len, b.len); i++)
		{
			int x = g;
			if(i < len) x += s[i];
			if(i < b.len) x += b.s[i];
			c.s[c.len++] = x % 10;
			g = x / 10;
		}
		return c;
	}
	bign operator += (const bign &b)
	{
		*this = *this + b;
		return *this;
	}
	void clean()
	{
		while(len > 1 && !s[len-1]) len--;
	}
	bign operator * (const bign &b) //*
	{
		bign c;
		c.len = len + b.len;
		for(int i = 0; i < len; i++)
		{
			for(int j = 0; j < b.len; j++)
			{
				c.s[i+j] += s[i] * b.s[j];
			}
		}
		for(int i = 0; i < c.len; i++)
		{
			c.s[i+1] += c.s[i]/10;
			c.s[i] %= 10;
		}
		c.clean();
		return c;
	}
	bign operator *= (const bign &b)
	{
		*this = *this * b;
		return *this;
	}
	bign operator - (const bign &b)
	{
		bign c;
		c.len = 0;
		for(int i = 0, g = 0; i < len; i++)
		{
			int x = s[i] - g;
			if(i < b.len) x -= b.s[i];
			if(x >= 0) g = 0;
			else
			{
				g = 1;
				x += 10;
			}
			c.s[c.len++] = x;
		}
		c.clean();
		return c;
	}
	bign operator -= (const bign &b)
	{
		*this = *this - b;
		return *this;
	}
	bign operator / (const bign &b)
	{
		bign c, f = 0;
		for(int i = len-1; i >= 0; i--)
		{
			f = f*10;
			f.s[0] = s[i];
			while(f >= b)
			{
				f -= b;
				c.s[i]++;
			}
		}
		c.len = len;
		c.clean();
		return c;
	}
	bign operator /= (const bign &b)
	{
		*this  = *this / b;
		return *this;
	}
	bign operator % (const bign &b)
	{
		bign r = *this / b;
		r = *this - r*b;
		return r;
	}
	bign operator %= (const bign &b)
	{
		*this = *this % b;
		return *this;
	}
	bool operator < (const bign &b)
	{
		if(len != b.len) return len < b.len;
		for(int i = len-1; i >= 0; i--)
		{
			if(s[i] != b.s[i]) return s[i] < b.s[i];
		}
		return false;
	}
	bool operator > (const bign &b)
	{
		if(len != b.len) return len > b.len;
		for(int i = len-1; i >= 0; i--)
		{
			if(s[i] != b.s[i]) return s[i] > b.s[i];
		}
		return false;
	}
	bool operator == (const bign &b)
	{
		return !(*this > b) && !(*this < b);
	}
	bool operator != (const bign &b)
	{
		return !(*this == b);
	}
	bool operator <= (const bign &b)
	{
		return *this < b || *this == b;
	}
	bool operator >= (const bign &b)
	{
		return *this > b || *this == b;
	}
	string str() const
	{
		string res = "";
		for(int i = 0; i < len; i++) res = char(s[i]+'0') + res;
		return res;
	}
};

istream& operator >> (istream &in, bign &x)
{
	string s;
	in >> s;
	x = s.c_str();
	return in;
}

ostream& operator << (ostream &out, const bign &x)
{
	out << x.str();
	return out;
}

bign gcd(bign a,bign b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

bign extgcd(bign a,bign b,bign &x,bign &y){
	bign d=a;
	if(b!=0){
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}else{
		x=1;y=0;
	}
	return d;
}

int main(){
	bign a,b,c;
	while(1){
		cin>>a>>b>>c;
		if(a==0&&b==0){
			if(c!=0){
				printf("Unquibable!\n");
				continue;
			}
			else
				break;
		}else if(a==0){
			if((c%b)!=0){
				printf("Unquibable!\n");
			}else{
				if((c/b)==1)
					cout<<0<<" fooms and "<<1<<" foob for a twob!\n";
				else
					cout<<0<<" fooms and "<<c/b<<" foobs for a twob!\n";
			}
			continue;
		}else if(b==0){
			if(c%a!=0){
				printf("Unquibable!\n");
			}else{
				if(c/a==1)
					cout<<1<<" foom and "<<0<<" foobs for a twob!\n";
				else
					cout<<c/a<<" fooms and "<<0<<" foobs for a twob!\n";
			}
			continue;
		}
		bign x0,y0,d;
		d=extgcd(a,b,x0,y0);
		if(c%d!=0){
			printf("Unquibable!\n");
			continue;
		}
		x0=c/d*x0;
		y0=c/d*y0;
//		cout<<x0<<' '<<y0<<' '<<d<<endl;
		bign bg=b/d,ag=a/d;
//		ll lb=-x0*d/b,ub=y0*d/a;
		bign lb,ub;
		if(x0*d%b==0)
			lb=(0-x0)*d/b;
		else if(0-x0<bign(0))
			lb=(0-x0)*d/b;
		else if(0-x0>bign(0))
			lb=(0-x0)*d/b+bign(1);
		else
			lb=0;
		if(y0*d%a==0)
			ub=y0*d/a;
		else if(y0*d/a>0)
			ub=y0*d/a;
		else if(y0*d/a<0)
			ub=y0*d/a-1;
		if(((x0+bg*lb<0||y0-ag*lb<0)&&(x0+bg*ub<0||y0-ag*ub<0))||ub<lb){
			printf("Unquibable!\n");
			continue;
		}
		bign t;
		if(bg-ag>0){
			t=lb;
		}else if(bg-ag<0)
			t=ub;
		else
			t=0;
//		cout<<lb<<" | "<<ub<<endl;
//		cout<<t<<'!'<<endl;
//		cout<<x0+bg*t<<" fooms and "<<y0-ag*t<<" foobs for a twob!"<<endl;
		if(x0+bg*t==1&&y0-ag*t==1){
			cout<<1<<" foom and "<<1<<" foob for a twob!\n";
		}else if(x0+bg*t==1)
			cout<<1<<" foom and "<<y0-ag*t<<" foobs for a twob!\n";
		else if(y0-ag*t==1)
			cout<<x0+bg*t<<" fooms and "<<1<<" foob for a twob!\n";
		else
			cout<<x0+bg*t<<" fooms and "<<y0-ag*t<<" foobs for a twob!\n";
	}
	return 0;
}
