#include<bits/stdc++.h>
using namespace std;

int base = 56;
int lim = base;


long long powers[10];

void power_calc()
{
	long long ans=1;
	powers[0]=ans;
	for(int i=1;i<10;i++)
	{
		ans*=base;
		powers[i]=ans;
	}
}

void count(int v[], int n, int dig)
{
	int A[lim], B[n], aux[n];
	for(int i=0;i<n;i++) aux[i]=v[i];
	for(int i=0;i<lim;i++) A[i]=0;
	for(int i=0;i<n;i++) 
	{
		int a= v[i];
		a%=powers[dig];
		a/=powers[dig-1];
		B[i]=a;
		A[a]++;
	}
	for(int i=1;i<lim;i++) A[i]+=A[i-1];
	for(int i=n-1;i>=0;i--)
	{
		v[A[B[i]]-1]=aux[i];
		A[B[i]]--;
	}
}

void radix(int v[], int n)
{
	for(int i=1;i<7;i++) count(v,n,i);
}

int main(int argc, char **argv)
{
	power_calc();
	int n;
	printf("Enter the number of array elements:- ");
	cin>>n;
	printf("\nEnter the array elements:-\n");
	int v[n];
	for(int i=0;i<n;i++) cin>>v[i];
	radix(v, n);
	cout<<"The sorted array is .....\n";
	for(int i=0;i<n;i++) cout<<v[i]<<" ";
	return 0;
}
