#ifndef __BigInt__
#define __BigInt__
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
class BigInt
{
   string _s;
  public:
   BigInt(){_s="0";}
   BigInt(const char* carr){_s=string(carr);removeFrontZeroes();}
   BigInt(string str){_s=str;removeFrontZeroes();}
   BigInt(const char c){_s=c;removeFrontZeroes();}
   BigInt(const long long int lli){for(long long int i=lli;i>0;i/=10)_s=(char)(i%10+'0')+_s;}
   BigInt(const int lli){for( int i=lli;i>0;i/=10)_s=(char)(i%10+'0')+_s;}
   BigInt(const BigInt& b){_s=b._s;}
   BigInt operator +(const BigInt);
   BigInt operator -(const BigInt);
   BigInt operator =(const BigInt b){_s=b._s;return *this;};
   void operator +=(const BigInt b){_s=((*this)+b)._s;}
   BigInt operator *(const char);
   BigInt operator *(const BigInt);
   bool operator >(const BigInt);
   bool operator >=(const BigInt b){return (*this>b)||(*this==b);}
   bool operator <(const BigInt b){return !(*this>=b);}
   bool operator <=(const BigInt b){return (*this<b)||(*this==b);}
   bool operator ==(const BigInt);
   bool operator !=(const BigInt b){return !(*this==b);}
   BigInt power(const int p);
   BigInt limitPower(int ,int);
   BigInt operator /(const int a){string s=_s;if(a==10)s.erase(s.length()-1,1);return BigInt(s);}
   char operator %(const int a){string s=_s;if(a==10)return s[s.length()-1];}
   char const& operator[](int i) const{return _s[i];}
   char& operator[](int i){return _s[i];}
   operator int() {int b=0;for(int i=0;i<_s.length();i++)b=(b*10+(_s[i]-'0'));return b;}
   
   friend ostream& operator <<(ostream& out,BigInt& b){out<<b._s;return out;}
   BigInt reverse(){string s;for(int i=_s.length()-1;i>=0;i--)s+=_s[i];return BigInt(s);}
   void reverseInit(){_s=reverse()._s;}
   bool isPalindrome(){for(int i=_s.length()-1,j=0;j<=i;i--,j++)if(_s[i]!=_s[j])return false;return true;}
   void removeFrontZeroes();
   int noOfDigits(){return _s.length();}
   BigInt sumOfDigits(){BigInt b;for(int i=0;i<_s.length();i++)b+=_s[i];return b;}
   void removeOtherThan(int a,int b){_s.erase(0,a);_s.erase(b-1,_s.length()-b);}
   void remove(int a,int b){_s.erase(a,b);}
   BigInt sumOfDigits(int x){BigInt b;for(int i=0;i<_s.length();i++)b+=(BigInt(_s[i]).power(x));return b;}
   
   //void resize();
};

#endif