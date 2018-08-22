#include<bits/stdc++.h>
using namespace std;

int partition(int v[], int p, int r)
{
	int x=rand()%(r-p+1) + p;
	int temp1= v[x];
	v[x]=v[r];
	v[r]=temp1;
	int i=p-1,val=v[r];
	int j=p;
	while(j<r)
	{
		if(v[j]<val)
		{
			i++;
			int temp=v[j];
			v[j]=v[i];
			v[i]=temp;
		}
		j++;
	}
	i++;
	int temp=v[j];
	v[j]=v[i];
	v[i]=temp;
	return i;
}

void quick(int v[], int in, int fi)
{
	if(in>=fi) return;
	int q=partition(v,in,fi);
	quick(v,in,q-1);
	quick(v,q+1,fi);
}

int main(int argc, char **argv)
{
	int n;
	srand((unsigned)time(0));
	printf("Enter the number of array elements:- ");
	cin>>n;
	printf("\nEnter the array elements:-\n");
	int v[n];
	for(int i=0;i<n;i++) cin>>v[i];
	quick(v, 0, n-1);
	cout<<"The sorted array is .....\n";
	for(int i=0;i<n;i++) cout<<v[i]<<" ";
	return 0;

}
