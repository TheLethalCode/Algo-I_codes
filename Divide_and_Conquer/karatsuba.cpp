#include<bits/stdc++.h>
using namespace std;

string trim(string x)
{
    int i=0;
    string c="";
    int n=x.length();
    while(i<n-1)
    {
        if(x[i]!='0')
            break;
        i++;            
    }
    for(;i<n;i++)
        c+=x[i];
    return c;
}

string operator+(string const& a,string const& b)
{
    int n=a.length(),m=b.length();
    string d="",c="";
    int n1=max(n,m);
    for(int i=0;i<n1-m;i++)
        d+='0';
    for(int i=0;i<n1-n;i++)
        c+='0';
    c+="0",d+="0";
    d+=b;
    c+=a;
    for(int i=n1;i>=0;i--)
    {
        c[i]+=d[i]-'0';
        if(c[i]>'9')
        {
            c[i]-=10;
            c[i-1]++;
        }
    }
    return trim(c);
}

string operator-(string const& a,string const& b)
{
    int n=a.length(),m=b.length();
    string d="";
    for(int i=0;i<n-m;i++)
        d+='0';
    d+=b;
    string c=a;
    for(int i=n-1;i>=0;i--)
    {
        if(c[i]<d[i])
        {
            c[i-1]--;
            c[i]+=10;
        }
        c[i]-=d[i]-'0';
    }
    return trim(c);
}

string operator<<(string const& a,int const& b)
{
    string c=a;
    for(int i=0;i<b;i++)
        c+='0';
    return trim(c);
}

string operator*(string const& x,string const& y)
{

    int n1=x.length(),n2=y.length();
    int n=max(n1,n2);
    string a="",b="";
    for(int i=0;i<n-n1;i++)
        a+='0';
    for(int i=0;i<n-n2;i++)
        b+='0';
    a+=x,b+=y;
    string Al="",Ar="",Bl="",Br="";
    if(n==1)
    {
        int ans=(a[0]-'0')*(b[0]-'0');
        string c="";
        if(ans/10)
            c+=ans/10+'0';
        c+=ans%10+'0';
        return c;
    }
    for(int i=0;i<n;i++)
    {
        if(i<ceil(n/2.0))
            Al+=a[i];
        else
            Ar+=a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(i<ceil(n/2.0))
            Bl+=b[i];
        else
            Br+=b[i];
    }
    // cout<<Al<<" "<<Ar<<" "<<Bl<<" "<<Br<<endl;
    string x1 = Al*Bl,y1=Ar*Br;
    string z = ((Al+Ar)*(Bl+Br) - (x1+y1));
    // cout<<x1<<" "<<y1<<" "<<z<<"%"<<endl;
    string ans =(x1<<int(2*(n/2)));
    string k=z<<int(ceil(n/2));
    ans=(ans+k);
    ans=ans+y1;
    return ans; 
}

int main()
{
    string a,b,x="",y="";
    cout<<"Input two numbers\n";
    cin>>a>>b;
    cout<<a*b;
}