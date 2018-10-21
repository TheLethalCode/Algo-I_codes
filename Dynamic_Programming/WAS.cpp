#include<bits/stdc++.h>
using namespace std;

#define pa pair<pair<int,int>,pair<int,int> >
#define fi first
#define se second

bool comp(pa const& a, pa const& b)
{
    return a.fi.se < b.fi.se;
}

void WAS(vector< pa >& v)
{
    int n=v.size();
    vector<int> ans(n,0),p(n);
    for(int i=0;i<n;i++)
    {
        int st=0,en=i-1,mid;
        while(en-st>1)
        {
            mid=(st+en)/2;
            if(v[mid].fi.se <= v[i].fi.fi)
                st=mid;
            else
                en=mid;
        }
        if(v[en].fi.se <= v[i].fi.fi)
            p[i]=en;
        else if(v[st].fi.se <= v[i].fi.fi)
            p[i]=st;
        else
            p[i]=-1;
    }
    
    ans[0]=v[0].se.fi;
    vector<bool> is(n);
    is[0]=true;
    for(int i=1;i<n;i++)
    {
        if(p[i]>=0)
        {
            if(ans[i-1] >= ans[p[i]]+v[i].se.fi)
            {
                ans[i]=ans[i-1];
                is[i]=false;
            }
            else
            {
                ans[i]=ans[p[i]]+v[i].se.fi;
                is[i]=true;
            }
        }
        else
        {
            if(ans[i-1] >= v[i].se.fi)
            {
                ans[i]=ans[i-1];
                is[i]=false;
            }
            else
            {
                ans[i]=v[i].se.fi;
                is[i]=true;
            }
        }
    }

    set<int> jobs;
    for(int i=n-1;i>=0;)
    {
        if(!is[i])
            i--;
        else
        {
            jobs.insert(v[i].se.se);
            int j=i-1;
            while(j>=0)
            {
                if(v[j].fi.se <= v[i].fi.fi)
                    break;
                j--;
            }
            i=j;
        }
    }

    cout<<"The jobs which result in maximum weight are\n";
    for(int x:jobs)
        cout<<x<<" ";
    cout<<endl;
    cout<<"Maximum weight acheivable is "<<ans[n-1]<<endl;
}

int main()
{
    int n;
    cout<<"No of tasks:- ";
    cin>>n;
    cout<<"Enter the start time, finish time and weight of the jobs\n";
    vector< pa > v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].fi.fi>>v[i].fi.se>>v[i].se.fi;
        v[i].se.se=i+1;
    }
    sort(v.begin(),v.end(),comp);
    WAS(v);
}