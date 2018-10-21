#include<bits/stdc++.h>
using namespace std;

#define pa pair<int, pair<int,int> >
#define fi first
#define se second

void solve(vector< pa >& v,int W)
{
    int n=v.size();
    vector< vector< int > > dp(n+1,vector<int>(W+1,0));
    for(int i=1;i<=n;i++)
        dp[i][0]=0;
    for(int i=0;i<=W;i++)
        dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(j<v[i-1].se.se)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i-1].se.se]+v[i-1].se.fi);
        }
    }
    cout<<"The maximum weight possible is "<<dp[n][W]<<endl;
}

int main()
{
    int n;
    cout<<"Enter the number of elements:- ";
    cin>>n;
    vector< pa > v(n);
    cout<<"Enter the value and weight of each element\n";
    for(int i=0;i<n;i++)
    {
        cin>>v[i].se.fi>>v[i].se.se;
        v[i].fi = i+1;
    }
    int w;
    cout<<"Enter the total weight accomodable:- ";
    cin>>w;
    solve(v,w);
}