#include<bits/stdc++.h>
using namespace std;

void Merge(int v[], int p, int q, int r)
{
	int n1=q-p+1,n2=r-q;
	int L[n1],R[n2];
	for(int i=0;i<n1;i++) L[i]=v[i+p];
	for(int i=0;i<n2;i++) R[i]=v[i+1+q];
	int a=0,b=0,c=p;
	while(a<n1 && b<n2)
	{
		if(L[a]<R[b]) v[c++]=L[a++];
		else v[c++]=R[b++];
	}
	while(a<n1) v[c++]=L[a++];
	while(b<n2) v[c++]=R[b++];
}

void merge_rec(int v[], int in, int fi)
{
	if(in>=fi) return;
	int mid = in+fi;
	mid/=2;
	merge_rec(v,in,mid);
	merge_rec(v,mid+1,fi);
	Merge(v,in,mid,fi);
}

int main(int argc, char **argv)
{
	int n;
	printf("Enter the number of array elements:- ");
	cin>>n;
	printf("\nEnter the array elements:-\n");
	int v[n];
	for(int i=0;i<n;i++) cin>>v[i];
	merge_rec(v, 0, n-1);
	cout<<"The sorted array is .....\n";
	for(int i=0;i<n;i++) cout<<v[i]<<" ";
	return 0;

}
