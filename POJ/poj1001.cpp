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

const int maxn=200;
struct bign{
	int len,s[maxn];

	bign(){
		memset(s,0,sizeof(s));
		len=1;
	}

	bign operator = (const char *num){
			len=strlen(num);
			for(int i=0;i<len;i++)
				s[i]=num[len-i-1]-'0';
			return *this;
	}

	bign operator = (int num){
		char s[maxn];
		sprintf(s,"%d",num);
		*this=s;
		return *this;
	}

	bign(int num){
		*this=num;
	}

	bign(const char *num){
		*this=num;
	}

	string str() const{
		string res="";
		for(int i=0;i<len;i++)
			res=(char)(s[i]+'0')+res;
		if(res=="")
			res="0";
		return res;
	}

	void clean(){
		while(len>1&&!s[len-1])
			len--;
	}

	bign operator + (const bign& b) const{
		bign c;
		c.len=0;
		for(int i=0,g=0;g||i<max(len,b.len);i++){
			int x=g;
			if(i<len)
				x+=s[i];
			if(i<b.len)
				x+=b.s[i];
			c.s[c.len++]=x%10;
			g=x/10;
		}
		return c;
	}
	
	bign operator - (const bign &b){
		bign c;
		c.len=0;
		for(int i=0,g=0;i<len;i++){
			int x=s[i]-g;
			if(i<b.len)
				x-=b.s[i];
			if(x>=0)
				g=0;
			else{
				g=1;
				x+=10;
			}
			c.s[c.len++]=x;
		}
		c.clean();
		return c;
	}

	bign operator * (const bign &b){
		bign c;
		c.len=len+b.len;
		for(int i=0;i<len;i++)
			for(int j=0;j<b.len;j++)
				c.s[i+j]+=s[i]*b.s[j];
		for(int i=0;i<c.len;i++){
			c.s[i+1]+=c.s[i]/10;
			c.s[i]%=10;
		}
		c.clean();
		return c;
	}

	bign operator -= (const bign &b){
		*this=*this-b;
		return *this;
	}

	bign operator / (const bign &b){
		bign c,f=0;
		for(int i=len-1;i>=0;i--){
			f=f*10;
			f.s[0]=s[i];
			while(f>=b){
				f-=b;
				c.s[i]++;
			}
		}
		c.len=len;
		c.clean();
		return c;
	}

	bign operator % (const bign &b){
		bign r=*this/b;
		r=*this-r*b;
		return r;
	}

	bign operator += (const bign &b){
		*this=*this+b;
		return *this;
	}

	bign operator *= (const bign &b){
		*this=*this*b;
		return *this;
	}

	bign operator /= (const bign &b){
		*this=*this/b;
		return *this;
	}

	bign operator %= (const bign &b){
		*this=*this%b;
		return *this;
	}

	bool operator < (const bign &b) const{
		if(len!=b.len)
			return len<b.len;
		for(int i=len-1;i>=0;i--)
			if(s[i]!=b.s[i])
				return s[i]<b.s[i];
		return false;
	}

	bool operator < (const int &b) const{
		bign c=b;
		if(len!=c.len)
			return len<c.len;
		for(int i=len-1;i>=0;i--)
			if(s[i]!=c.s[i])
				return s[i]<c.s[i];
		return false;
	}

	bool operator > (const bign &b) const{
		return b < *this;
	}
	
	bool operator > (const int b) const{
		bign c=b;
		return c<*this;
	}

	bool operator <= (const bign &b) const{
		return !(b<*this);
	}

	bool operator <= (const int b) const{
		bign c=b;
		return !(c<*this);
	}

	bool operator >= (const bign &b) const{
		return !(*this<b);
	}

	bool operator >= (const int b) const{
		bign c=b;
		return !(*this<c);
	}

	bool operator != (const bign &b) const{
		return b<*this||*this<b;
	}

	bool operator != (const int b) const{
		bign c=b;
		return c<*this||*this<b;
	}

	bool operator == (const bign &b) const{
		return !(b<*this)&&!(*this<b);
	}
	
	bool operator == (const int b) const{
		bign c=b;
		return !(c<*this)&&!(*this<c);
	}
};

istream& operator >> (istream &in,bign &x){
	string s;
	in>>s;
	x=s.c_str();
	return in;
}

ostream& operator << (ostream &out,const bign& x){
	out<<x.str();
	return out;
}

int main(){
	string r;int n;
	while(cin>>r>>n){
		int tmp=0;
		int dian=r.size()-1;
		bool find=false;
		for(int i=0;i<r.size();i++){
			if(r[i]!='.')
				tmp=tmp*10+(r[i]-'0');
			else{
				dian=i;
				find=true;
			}
		}
		if(tmp==0){
			printf("0\n");
			continue;
		}
		bign rr=tmp;
		bign ss=1;
		for(int i=1;i<=n;i++)
			ss=ss*rr;
	//	cout<<ss<<'?'<<endl;
		if(find==false){
			cout<<ss<<endl;
		}else{
			string os;
			int dl=r.size()-1-dian;
			dl=dl*n;
			if(dl<ss.len){
				for(int i=0;i<ss.len;i++){
					if(i==ss.len-dl)
						os.push_back('.');
					os.push_back('0'+ss.s[ss.len-1-i]);
				}
			}else{
				os.push_back('.');
				for(int i=0;i<dl;i++){
					if(i>=dl-ss.len){
						os.push_back('0'+ss.s[ss.len-1-(i-dl+ss.len)]);
					}
					else
						os.push_back('0');
				}
			}
	//		cout<<ss.len<<' '<<dl<<'!'<<endl;
			int b=0,e=os.size()-1;
			while(os[b]=='0')
				b++;
			while(os[e]=='0')
				e--;
			if(os[e]=='.')
				e--;
			string ans;
			for(int i=b;i<=e;i++)
				ans.push_back(os[i]);
			if(ans.size()==0)
				printf("0\n");
			else
				cout<<ans<<endl;
		}
	}	
	return 0;
}
