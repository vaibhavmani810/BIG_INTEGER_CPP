#include<iostream>
#include<vector>
#include<cstring>
#include<cassert>
#include"bigint.h"
using namespace std;

long long power(long long a,long long n,long long mod){
	int res=1;
	while(n){
		if((n&1)==1) res=(res*a)%mod;
		a=a*a;
		a%=mod;
		n=n>>1;
	}
	return res;
}

bigint::bigint(){
	digits.assign(1001,0);
	sz=1;
}

bigint::bigint(const string &num){
	digits.assign(1001,0);
	int len=num.size();
	int k=0;
	for(int i=len-1;i>=0;i--){
		digits[k++]=num[i]-'0';
	}
	sz=k;
}

bigint::bigint(const bigint &num){
	digits.assign(1001,0);
	sz=num.sz;
	for(int i=0;i<sz;i++){
		digits[i]=num.digits[i];
	}
}

bigint::bigint(const long long &nm){
	long long tm=nm;
	int sze=0;
	while(tm>0){
		sze++;tm/=10;
	}
	sz=max(1,sze);
	tm=nm;
	digits.assign(1001,0);
	for(int i=0;i<sz;i++){
		digits[i]=tm%10;
		tm/=10;
	}
}

ostream& operator<<(ostream& out, const bigint& num){
	for(int i=num.sz-1;i>=0;i--){
		out<<num.digits[i];
	}
	return out;
}

istream& operator>>(istream &in, bigint& num){
	num.digits.assign(1001,0);
	string s;
	in>>s;
	int ln=s.size();
	int l=0;
	int r=ln-1;
	while(l<r){
		char tmp=s[l];
		s[l]=s[r];
		s[r]=tmp;
		l++;
		r--;
	}
	int k=0;
	for(int i=0;i<ln;i++){
		num.digits[k++]=s[i]-'0';
	}
	num.sz=k;
	return in;
}

bigint& bigint::operator=(const bigint &num){
	if(this==&num) return *this;
	sz=num.sz;
	digits.assign(1001,0);
	for(int i=0;i<sz;i++){
		digits[i]=num.digits[i];
	}
	return *this;
}

bigint& bigint::operator=(const long long &num){
	long long tm=num;
	int sze=0;
	while(tm>0){
		sze++;tm/=10;
	}
	sz=max(sz,sze);
	tm=num;
	digits.assign(1001,0);
	for(int i=0;i<sz;i++){
		digits[i]=tm%10;
		tm/=10;
	}
	return *this;
}


bigint bigint::operator+(const bigint &num){
	bigint res;
	int carry=0;
	for(int i=0;i<1001;i++){
		int x=digits[i]+num.digits[i];
		int tempc=(carry+x);
		res.digits[i]=tempc%10;
		carry=tempc/10;
	}
	for(int i=1000;i>=0;i--){
		if(res.digits[i]!=0){
			res.sz=i+1;
			break;
		}
	}
	return res;
}

bigint bigint::operator*(const bigint &num){
	bigint res;
	for(int i=0;i<num.sz;i++){
		int dg=num.digits[i];
		int carry=0;
		for(int j=0;j<sz;j++){
			int prd=dg*digits[j];
			res.digits[j+i]+=(prd+carry)%10;
			carry=(prd+carry)/10;
			carry+=res.digits[i+j]/10;
			res.digits[i+j]%=10;
			res.sz=max(res.sz,i+j+1);
		}
		for(int j=sz;j<1001 && carry;j++){
			res.digits[i+j]+=carry%10;
			carry/=10;
			res.sz=max(res.sz,i+j+1);
		}
	}
	return res;
}

bigint bigint::operator*(const long long &nm){
	bigint res;
	bigint num=nm;
	for(int i=0;i<num.sz;i++){
		int dg=num.digits[i];
		int carry=0;
		for(int j=0;j<sz;j++){
			int prd=dg*digits[j];
			res.digits[j+i]+=(prd+carry)%10;
			carry=(prd+carry)/10;
			carry+=res.digits[i+j]/10;
			res.digits[i+j]%=10;
			res.sz=max(res.sz,i+j+1);
		}
		for(int j=sz;j<1001 && carry;j++){
			res.digits[i+j]+=carry%10;
			carry/=10;
			res.sz=max(res.sz,i+j+1);
		}
	}
	return res;
}

bigint bigint::operator%(bigint &nm){
	try{
		long long mod=nm;
		if(mod==0){
			throw "Division by Zero Error";
		}
		long long ans=0;
		for(int i=0;i<sz;i++){
			long long tmp=(digits[i]*power(10,i,mod));
			ans=(ans+tmp%mod)%mod;
		}
		bigint res(ans);
		return res;
	}
	catch(const char* exception){
		std::cerr<<"ERROR : "<<exception<<endl;
	}
	long long ans=0;
	bigint res(ans);
	return res;
}

bool operator<(const bigint &n1, const bigint &n2){
	if(n1.sz<n2.sz) return true;

	if(n1.sz>n2.sz) return false;

	for(int i=n1.sz-1;i>=0;i--){
		if(n1.digits[i]<n2.digits[i]){
			return true;
		}
		if(n1.digits[i]>n2.digits[i]){
			return false;
		}
	}
	return false;
}

bool operator==(const bigint &n1, const bigint &n2){
	if(n1.sz!=n2.sz) return false;
	for(int i=0;i<1001;i++){
		if(n1.digits[i]!=n2.digits[i]){
			return false;
		}
	}
	return true;
}

bool operator!=(const bigint &n1, const bigint &n2){
	if(n1.sz!=n2.sz) return true;
	for(int i=0;i<1001;i++){
		if(n1.digits[i]!=n2.digits[i]){
			return true;
		}
	}
	return false;
}

bool operator>(const bigint &n1, const bigint &n2){
	if(n1<n2) return false;
	if(n1==n2) return false;

	return true;
}

bool operator<=(const bigint &n1, const bigint &n2){
	if(n1==n2 || n1<n2) return true;
	return false;
}

bool operator>=(const bigint &n1, const bigint &n2){
	if(n1==n2 || n1>n2) return true;
	return false;
}

std::string to_string(const bigint &num){
	std::string res;
	for(int i=num.sz-1;i>=0;i--){
		res+=num.digits[i]+'0';
	}
	return res;
}

bigint::operator long long(){
	assert(sz<=18);
	long long res=0;
	for(int i=sz;i>=0;i--){
		res=res*10+digits[i];
	}
	return res;
}
