#include<bits/stdc++.h>
using namespace std;

#define pa pair< int,int > 
#define fi first 
#define se second
#define pb push_back
#define mp make_pair

bool comp(pa const& x, pa const& y)
{
    if(x.fi == y.fi)
        return x.se<y.se;
    return x.fi<y.fi;
}

bool comp1(pa const& x, pa const& y)
{
    if(x.se == y.se)
        return x.fi<y.fi;
    return x.se<y.se;
}

double dist(pa x, pa y)
{
    return sqrt((x.fi-y.fi)*(x.fi-y.fi) + (x.se-y.se)*(x.se-y.se));
}

double dist(pair< pa,pa> p)
{
    return sqrt((p.fi.fi-p.se.fi)*(p.fi.fi-p.se.fi) + (p.fi.se-p.se.se)*(p.fi.se-p.se.se));
}

pair< pa,pa > merge(vector< pa > y, double d,int xp)
{
    vector< pa > red;
    for(pa x : y)
    {
        if(fabs(x.fi-xp)>d)
            continue;
        red.pb(x);
    }
    int n=red.size();
    double mi = 1e9;
    pair< pa, pa > mip;
    for(int i=0;i<n;i++)
    {
        pa p = red[i];
        int j=i+1;
        while(j<n)
        {
            if(red[j].se-p.se > d)
                break;
            if(dist(red[j],p)<mi)
            {
                mi=dist(red[j],p);
                mip = mp(red[j],p);
            }
            j++;
        }
    }
    return mip;
}

pair< pa, pa > find_closest(vector< pa > x_s, vector< pa > y_s)
{
    int n=x_s.size();
    if(n==2)
        return mp(x_s[0],x_s[1]);
    if(n==3)
    {
        if(dist(x_s[0],x_s[1])<=dist(x_s[1],x_s[2]) && dist(x_s[0],x_s[1])<=dist(x_s[0],x_s[2]))
            return mp(x_s[0],x_s[1]);
        if(dist(x_s[2],x_s[1])<=dist(x_s[1],x_s[0]) && dist(x_s[2],x_s[1])<=dist(x_s[0],x_s[2]))
            return mp(x_s[2],x_s[1]);
        return mp(x_s[2],x_s[0]);
    }
    int mid=(n-1)/2;
    int xp=x_s[mid].fi,yp=x_s[mid].se;
    vector< pa > xl,xr,yl,yr;
    for(int i=0;i<n;i++)
    {
        if(x_s[i].fi < xp)
            xl.pb(x_s[i]);
        else if(x_s[i].fi == xp && x_s[i].se <= yp)
            xl.pb(x_s[i]);
        else
            xr.pb(x_s[i]);
        if(y_s[i].fi < xp)
            yl.pb(y_s[i]);
        else if(y_s[i].fi == xp && y_s[i].se <= yp)
            yl.pb(y_s[i]);
        else
            yr.pb(y_s[i]);
    }
    pair< pa,pa > l = find_closest(xl,yl), r = find_closest(xr,yr);
    double dl=dist(l),dr=dist(r),dm;
    pair< pa,pa > m = merge(y_s,min(dl,dr),xp);
    dm=dist(m);
    if(dl<=dr && dl<=dm)
        return l;
    else if(dr<=dl && dr<=dm)
        return r;
    else
        return m;
}

void closest(vector< pa > v)
{
    int n=v.size();
    vector< pa > x_sorted = v;
    sort(v.begin(),v.end(),comp1);
    vector< pa > y_sorted = v;
    pair< pa,pa > p = find_closest(x_sorted,y_sorted);
    printf("(%d,%d) (%d,%d) Distance = %lf\n",p.fi.fi,p.fi.se,p.se.fi,p.se.se,dist(p));
}

int main()
{
    int n;
    cout<<"Enter  number of points :- ";
    cin>>n;
    vector< pa > v(n),k;
    cout<<"Enter the points\n";
    for(int i=0;i<n;i++)
        cin>>v[i].fi>>v[i].se;
    sort(v.begin(),v.end(),comp);
    pa temp = v[0];
    for(int i=1;i<n;i++)
    {
        pa h=v[i];
        if(h.fi == temp.fi && h.se == temp.se)
        {
            printf("(%d,%d) (%d,%d) Distance = %lf\n",temp.fi,temp.se,h.fi,h.se,dist(temp,h));
            exit(0);
        }
        temp = h;
    }
    closest(v);
}