#include<bits/stdc++.h>
using namespace std;

#define pa pair< int,pair<int,int> >
#define fi first
#define se second

// Greedy - Finish Time

bool comp(pa const& a, pa const& b)
{
    return a.se.se < b.se.se;
}

void AS(vector<pa>& v)
{
    int n=v.size();
    int i=0,ans=1;
    vector< int > jobs;
    jobs.push_back(v[0].fi);
    while(i<n)
    {
        int j=i+1;
        while(j<n)
        {
            if(v[j].se.fi >= v[i].se.se)
                break;
            j++;
        }
        if(j==n)
            break;
        jobs.push_back(v[j].fi);
        ans++;
        i=j;
    }
    sort(jobs.begin(),jobs.end());
    cout<<"One set of maximum activities is\n";
    for(int x:jobs)
        cout<<x<<" ";
    cout<<endl;
    cout<<"Maximum no. of activities that can be selected is "<<ans<<endl;
}

int main()
{
    int n;
    cout<<"Enter the number of tasks:- ";
    cin>>n;
    vector< pa > v(n);
    cout<<"Enter the start and finish time of the tasks\n";
    for(int i=0;i<n;i++)
    {
        cin>>v[i].se.fi>>v[i].se.se;
        v[i].fi=i+1;
    }
    sort(v.begin(),v.end(),comp);
    AS(v);
}