#include"bigint.h"
using namespace std;

BigInt BigInt::operator +(const BigInt b)
{
    int i,j,carry=0;
    string str;
    for(i=_s.length()-1,j=b._s.length()-1;i>=0||j>=0;i--,j--)
    {int a,d;
    if(i<0&&j>=0)
    {a=0;d=b._s[j]-'0';}
    else if(j<0&&i>=0)
    {d=0;a=_s[i]-'0';}
    else
    {a=_s[i]-'0';d=b._s[j]-'0';}
    //cout<<i<<"\t"<<j<<"\t";
    int c=a+d+carry;
    carry=c/10;
    str=(char)(c%10+'0')+str;
    //cout<<a<<"\t"<<d<<"\t"<<str<<"\t"<<carry<<endl;
    
    }
    while(carry>0)
    {
    str=(char)(carry%10+'0')+str;
    carry/=10;
    }
  return BigInt(str);  
}


BigInt BigInt::operator -(const BigInt b)
{
	if(!(*this > b))
		return BigInt("0");
    int i,j,borrow=0;
    string str;
    for(i=_s.length()-1,j=b._s.length()-1;i>=0||j>=0;i--,j--)
    {int a,d;
    if(i<0&&j>=0)
    {a=0;d=b._s[j]-'0';}
    else if(j<0&&i>=0)
    {d=0;a=_s[i]-'0';}
    else
    {a=_s[i]-'0';d=b._s[j]-'0';}
    //cout<<i<<"\t"<<j<<"\t";
	int c = 0;
	if(borrow == 1)
	{
		a -= 1;
		borrow = 0;
	}
	if(a < d)
	{
		borrow = 1;
		c = a + 10 - d;
	}
	else
	{
		borrow = 0;
		c = a - d;
	}
    
    
    str=(char)(c%10+'0')+str;
    //cout<<a<<"\t"<<d<<"\t"<<c<<"\t"<<str<<"\t"<<borrow<<endl;
    
    }
    BigInt ret = BigInt(str);
	ret.removeFrontZeroes();
  return ret;  
}



BigInt BigInt::operator *(const char c)
{
    int i,j=c-'0',ai,carry=0;
    string str;
    for(i=_s.length()-1;i>=0;i--)
    {int a=_s[i]-'0';
    //cout<<i<<"\t"<<j<<"\t";
    int d=(a*j)+carry;
    carry=d/10;
    str=(char)(d%10+'0')+str;
    //cout<<a<<"\t"<<d<<"\t"<<str<<"\t"<<carry<<endl;
    
    }
    while(carry>0)
    {
    str=(char)(carry%10+'0')+str;
    carry/=10;
    }
  return BigInt(str);  
}


BigInt BigInt::operator *(const BigInt p)
{int i;
BigInt b=p;
    BigInt carry;
    string str;
    for(i=_s.length()-1;i>=0;i--)
    {char a=_s[i];
    //cout<<i<<"\t"<<j<<"\t";
    BigInt d=(b*a)+carry;
    //cout<<d<<"\t"<<carry<<endl;
    carry=d/10;
    str=(char)(d%10)+str;
    //cout<<a<<"\t"<<d<<"\t"<<str<<"\t"<<carry<<endl;
    
    }
    if(carry._s.length()==1&&carry._s[0]=='0')
    return BigInt(str);  
    else
    return BigInt(carry._s+str);
    

    
  }


BigInt BigInt::power(int p)
{
    if(p==0)
    return BigInt('1');
    if(p==1)
    return *this;
    if(p==2)
    return (*this)*(*this);
    if(p%2==0)
    return (this->power(2)).power(p/2);
    else
    return (*this)*(this->power(p-1));
    
}

BigInt BigInt::limitPower(int p,int n)
{
  if(noOfDigits()>n)
  {
    removeOtherThan(noOfDigits()-n,n);
  }
  if(p==0)
    return BigInt('1');
    if(p==1)
    return *this;
    if(p==2)
    return (*this)*(*this);
    if(p%2==0)
    return (this->limitPower(2,n)).limitPower(p/2,n);
    else
    return (*this)*(this->limitPower(p-1,n));
    

}

void BigInt::removeFrontZeroes()
   {
    for(int i=0;i<_s.length();i++)
   {
    if(_s[i]!='0')
   return;
   else if(i!=_s.length()-1)
   {_s.erase(i,1);i=-1;}
   }
   }
   
   
   
   bool BigInt::operator >(const BigInt b)
   {
    if(_s.length()>b._s.length())
    return true;
    if(_s.length()<b._s.length())
    return false;
    if(_s.length()==b._s.length())
    {
        for(int i=0;i<_s.length();i++)
        if(_s[i]<b._s[i])
        return false;
    else if(_s[i]>b._s[i])
        return true;
    return false;
    }
   }
   bool BigInt::operator ==(const BigInt b)
   {
    if(_s.length()!=b._s.length())
    return false;
    if(_s.length()==b._s.length())
    {
        for(int i=0;i<_s.length();i++)
        if(_s[i]!=b._s[i])
        return false;
        return true;
    }
   }
   
   