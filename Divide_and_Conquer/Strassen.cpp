#include<bits/stdc++.h>
using namespace std;

struct matrix
{
    int **A,row_start,row_end,col_start,col_end,rows,cols;
    matrix(int n,int m)
    {
        rows=n,cols=m;
        A=new int*[n+1];
        for(int i=1;i<n+1;i++)
            A[i]= new int[m+1];
        for(int i=1;i<n+1;i++)
            for(int j=1;j<m+1;j++)
                A[i][j]=0;
        row_start=1,row_end=n,col_start=1,col_end=m;
    }
    matrix(matrix B,int rs,int re,int cs,int ce)
    {
        row_start=rs,row_end=re,col_start=cs,col_end=ce;
        A=B.A;
        rows=re-rs+1,cols=ce-cs+1;
    }
    matrix(matrix B,int n,int m)
    {
        row_start=1,row_end=n,col_start=1,col_end=m;
        rows=n,cols=m;
        A=new int*[n+1];
        for(int i=1;i<n+1;i++)
            A[i]= new int[m+1];
        for(int i=1;i<n+1;i++)
            for(int j=1;j<m+1;j++)
                A[i][j]=B.A[i][j];
    }
    matrix(int x)
    {
        A=new int*[2];
        A[1]=new int[2];
        A[1][1]=x;
        row_start=row_end=col_start=col_end=rows=cols=1;
    }
};

ostream & operator<<(ostream &out, matrix &A)
{
    for(int i=A.row_start;i<=A.row_end;i++)
    {
        for(int j=A.col_start;j<=A.col_end;j++)
            out<<A.A[i][j]<<" ";
        out<<endl;
    }
} 

matrix operator+(matrix A,matrix B)
{
    matrix C(A.rows,A.cols);
    for(int i=0;i<A.rows;i++)
        for(int j=0;j<A.cols;j++)
            C.A[i+1][j+1]=A.A[A.row_start+i][A.col_start+j]+B.A[B.row_start+i][B.col_start+j];
    C.rows=A.rows,C.cols=A.cols;
    C.row_start=1,C.row_end=A.rows,C.col_start=1,C.col_end=A.cols;
    return C;
}

matrix operator-(matrix A,matrix B)
{
    matrix C(A.rows,A.cols);
    for(int i=0;i<A.rows;i++)
        for(int j=0;j<A.cols;j++)
            C.A[i+1][j+1]=A.A[A.row_start+i][A.col_start+j]-B.A[B.row_start+i][B.col_start+j];
    C.rows=A.rows,C.cols=A.cols;
    C.row_start=1,C.row_end=A.rows,C.col_start=1,C.col_end=A.cols;
    return C;
}

matrix operator*(matrix A,matrix B)
{
    int n1=A.row_start+A.row_end-1,m1=A.col_start+A.col_end-1;
    int n2=B.row_start+B.row_end-1,m2=B.col_start+B.col_end-1;
    int n=A.rows;
    if(A.rows==1)
    {
        matrix C(A.A[A.row_start][A.col_start]*B.A[B.row_start][B.col_start]);
        return C;
    }
    matrix A11(A,A.row_start,n1/2,A.col_start,m1/2),A12(A,A.row_start,n1/2,m1/2+1,A.col_end);
    matrix A21(A,n1/2+1,A.row_end,A.col_start,m1/2),A22(A,n1/2+1,A.row_end,m1/2+1,A.col_end);
    matrix B11(B,B.row_start,n2/2,B.col_start,m2/2),B12(B,B.row_start,n2/2,m2/2+1,B.col_end);
    matrix B21(B,n2/2+1,B.row_end,B.col_start,m2/2),B22(B,n2/2+1,B.row_end,m2/2+1,B.col_end);
    matrix S1=B12-B22,S2=A11+A12,S3=A21+A22,S4=B21-B11,S5=A11+A22,S6=B11+B22,S7=A12-A22,S8=B21+B22,S9=A11-A21,S10=B11+B12;
    matrix P1=A11*S1,P2=S2*B22,P3=S3*B11,P4=A22*S4,P5=S5*S6,P6=S7*S8,P7=S9*S10;
    matrix C(n,n),C11=(((P5+P4)-P2)+P6),C12=(P1+P2),C21=(P3+P4),C22=(((P5+P1)-P3)-P7);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i<=n/2 && j<=n/2)
                C.A[i][j]=C11.A[i][j];
            else if(i<=n/2)
                C.A[i][j]=C12.A[i][j-n/2];
            else if(i>n/2 && j<=n/2) 
                C.A[i][j]=C21.A[i-n/2][j];
            else
                C.A[i][j]=C22.A[i-n/2][j-n/2];
        }
    return C;
}

int main()
{
    cout<<"Enter the rows and cols of the first matrix n1,m1:-";
    int n1,m1,n2,m2;
    cin>>n1>>m1;
    cout<<"Enter the rows and cols of the second matrix n2,m2:-";
    cin>>n2>>m2;

    if(n2!=m1)
    {
        cout<<"Cannot multiply matrix\n";
        exit(1);
    }

    int x=1<<int(ceil(log2(max(n1,m1)))),y=1<<int(ceil(log2(max(m1,m2))));
    matrix A(max(x,y),max(x,y)),B(max(x,y),max(x,y));
    cout<<"Enter the first matrix:-\n";
    for(int i=1;i<=n1;i++)
        for(int j=1;j<=m1;j++)
            cin>>A.A[i][j];
    
    cout<<"Enter the second matrix:-\n";
    for(int i=1;i<=n2;i++)
        for(int j=1;j<=m2;j++)
            cin>>B.A[i][j];
    // cout<<"Matrix A"<<endl<<A;
    // cout<<"Matrix B"<<endl<<B;
    
    matrix C(A*B,n1,m2);
    cout<<"\nMatrix A*B:"<<endl<<C;
}