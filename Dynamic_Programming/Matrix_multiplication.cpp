#include<bits/stdc++.h>
using namespace std;

#define pa pair<int,int>
#define fi first
#define se second
#define pb push_back

void print(vector< vector<int > >& B,int st,int en)
{
    if(st==en)
        cout<<"A"<<st+1;
    else
    {
        cout<<"(";
        print(B,st,B[st][en]);
        print(B,B[st][en]+1,en);
        cout<<")";
    }
}

void chain(vector< pa >& v)
{
    int n=v.size();
    vector< vector< int > > A(n,vector<int>(n,1e9)),B(n,vector<int>(n));
    for(int i=0;i<n;i++)
        A[i][i]=0;
    for(int l=1;l<=n;l++)
        for(int i=0;i<n-l+1;i++)
        {
            int j=i+l-1;
            for(int k=i;k<j;k++)
            {
                int temp= A[i][k]+A[k+1][j]+v[i].fi*v[j].se*v[k].se;
                if(temp<A[i][j])
                {
                    A[i][j]=temp;
                    B[i][j]=k;
                }
            }
        }
    print(B,0,n-1);
    cout<<endl<<"Cost="<<A[0][n-1]<<endl;
}

int main()
{
    int n;
    cin>>n;
    vector< pa > v(n);
    for(int i=0;i<n;i++)
        cin>>v[i].fi>>v[i].se;
    chain(v);
}