#include<bits/stdc++.h>
using namespace std;

// MAX_HEAP IMPLEMENTED

int heap_size;

void heapify_up(vector< int >& v,int in)
{
    int parent=in/2;
    if(parent<1) 
        return;
    if(v[in]>v[parent])
    {
        swap(v[in],v[parent]);
        heapify_up(v,parent);
    }
}

void heapify_down(vector< int>& v,int in)
{
    int left=2*in,right=2*in+1,largest=in;
    if(left<=heap_size)
        if(v[left]>v[in])
            largest=left;
    if(right<=heap_size)
        if(v[right]>v[largest])
            largest=right;
    swap(v[in],v[largest]);
    if(in!=largest)
        heapify_down(v,largest);
}

void build_heap(vector<int>& v)
{
    int n=v.size()-1;
    heap_size=n;
    for(int i=n/2;i>0;i--)
        heapify_down(v,i);
}

void heap_sort(vector<int>& v)
{
    build_heap(v);
    while(heap_size>1)
    {
        swap(v[1],v[heap_size]);
        heap_size--;
        heapify_down(v,1);
    }
}

int main()
{
    int n;
    cout<<"Enter the number of elements:- ";
    cin>>n;
    vector< int > v(n+1);
    cout<<"Enter the elements\n";
    for(int i=1;i<=n;i++)
        cin>>v[i];
    heap_sort(v);
    for(int i=1;i<=n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}