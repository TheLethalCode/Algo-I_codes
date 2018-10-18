#include<bits/stdc++.h>
using namespace std;

int max_array(int *A,int a,int b,int *l,int *r)
{
    if(a==b)
    {
        return A[a];
        *l=a,*r=b;
    }
    int mid=(a+b)/2;
    int le=-1e9,ri=-1e9,ma,temp=0;
    int start,end=mid,l1,l2,r1,r2;
    for(int i=mid;i>=a;i--)
    {
        temp+=A[i];
        if(temp>le)
        {
            le=temp;
            start=i;
        }
    }
    temp=0;
    for(int i=mid+1;i<=b;i++)
    {
        temp+=A[i];
        if(temp>ri)
        {
            ri=temp;
            end=i;
        }
    }
    ma=le+ri;
    int left=max_array(A,a,mid,&l1,&r1),right=max_array(A,mid+1,b,&l2,&r2);
    if(left>=right)
    {
        if(left>=ma)
        {
            *l=l1,*r=r1;
            return left;
        }
        else
        {
            *l=start,*r=end;
            return ma;
        }
    }
    else 
    {
        if(right>=ma)
        {
            *l=l2,*r=r2;
            return right;
        }
        else
        {
            *l=start,*r=end;
            return ma;
        }
    }
}

int main()
{
    cout<<"Enter the number of elements:- ";
    int n;
    cin>>n;
    cout<<"Enter the elements:-\n";
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    int st,en;
    cout<<max_array(A,0,n-1,&st,&en)<<endl;
    printf("(%d,%d)\n",st,en);
    return 0;
}