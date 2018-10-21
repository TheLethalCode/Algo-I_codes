#include<bits/stdc++.h>
using namespace std;

void LCS(string s1, string s2)
{
    int n=s1.length(),m=s2.length();
    int A[m+1][n+1]={0};
    for(int i=0;i<=m;i++)
        A[i][0]=0;
    for(int i=0;i<=n;i++)
        A[0][i]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s2[i-1]==s1[j-1])
                A[i][j]=A[i-1][j-1]+1;
            else
                A[i][j]=max(A[i-1][j],A[i][j-1]);
        }
    }
    int i=m,j=n,cnt=A[m][n]-1;
    char ans[cnt+2];
    ans[cnt+1]='\0';
    while(i!=0 && j!=0)
    {
        if(s2[i-1]==s1[j-1])
            ans[cnt--]=s2[i-1],i--,j--;
        else if(A[i][j-1] > A[i-1][j])
            j--;
        else
            i--;
    }
    cout<<"LCS = "<<ans<<endl;
    cout<<"LCS Length = "<<strlen(ans)<<endl;
}

int main()
{
    cout<<"Enter the two strings\n";
    string s1,s2;
    cin>>s1>>s2;
    LCS(s1,s2);
}