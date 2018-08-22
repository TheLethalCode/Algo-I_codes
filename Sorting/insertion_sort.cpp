#include<bits/stdc++.h>
using namespace std;

void insert(int v[], int n)
{
	for(int i=1;i<n;i++)
	{
		int j=i-1;
		int val=v[i];
		while(j>=0)
		{
			if(v[j]>val)
			{
				v[j+1]=v[j];
				j--;
			}
			else break;
		}
		v[j+1]=val;
	}
}

int main(int argc, char **argv)
{
	int n;
        printf("Enter the number of array elements:- ");
        cin>>n;
        printf("\nEnter the array elements:-\n");
        int v[n];
        for(int i=0;i<n;i++) cin>>v[i];
        insert(v, n);
        cout<<"The sorted array is .....\n";
        for(int i=0;i<n;i++) cout<<v[i]<<" ";
        return 0;

}
