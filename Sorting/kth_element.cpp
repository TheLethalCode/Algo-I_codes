#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& v,int p,int r)
{
    int x=rand()%(r-p+1)+p;
    swap(v[x],v[r]);
    int i=p-1,j=p;
    while(j<r)
    {
        if(v[j]<v[r])
        {
            swap(v[j],v[i+1]);
            i++;
        }
        j++;
    }
    swap(v[r],v[i+1]);
    return i+1;
}

// Expected linear time
int find_k(vector<int>& v,int st,int en,int k)
{
    if(st==en && st==k-1)
        return v[k-1];
    int q=partition(v,st,en);
    if(q==k-1)
        return v[k-1];
    if(q<k-1)
        return find_k(v,q+1,en,k);
    return find_k(v,st,q-1,k);
}

int main()
{
    srand((unsigned)time(0));
    int n;
    cout<<"Enter the no. of elements:- ";
    cin>>n;
    vector< int > v(n);
    cout<<"Enter the elemensts\n";
    for(int i=0;i<n;i++)
        cin>>v[i];
    int k;
    cout<<"Enter k:- ";
    cin>>k;
    cout<<find_k(v,0,n-1,k)<<endl;   
}