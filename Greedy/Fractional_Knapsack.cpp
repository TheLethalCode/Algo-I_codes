#include<bits/stdc++.h>
using namespace std;

#define pa pair< int, pair<int,int> >
#define fi first
#define se second

bool comp(pa const& x,pa const& y)
{
    return x.se.fi*1.0/x.se.se > y.se.fi*1.0/y.se.se;
}

void solve(vector< pa >& v,int W)
{
    int n=v.size();
    int ans=0,i=0;
    double value=0;
    vector< double > a(n+1,0);
    while(i<n && ans<W)
    {
        if(v[i].se.se <= W-ans)
        {
            a[v[i].fi]=1;
            ans+=v[i].se.se;
            value+=v[i].se.fi;
        }
        else
        {
            a[v[i].fi]=(W-ans)*1.0/v[i].se.se;
            value+=v[i].se.fi*a[v[i].fi];
            ans=W;
        }
        i++;
    }
    cout<<"The fraction that each job element is assigned to maximise the value is\n";
    for(int i=1;i<=n;i++)
        cout<<fixed<<setprecision(2)<<a[i]<<" ";
    cout<<"\nThe maximum value is "<<value<<endl;
}

int main()
{
    int n;
    cout<<"Enter the number of elements:- ";
    cin>>n;
    cout<<"Enter the value and weight of each element\n";
    vector< pa > v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].se.fi>>v[i].se.se;
        v[i].fi = i+1;
    }
    cout<<"Enter the total capacity:- ";
    int w;
    cin>>w;
    sort(v.begin(),v.end(),comp);
    solve(v,w);
}