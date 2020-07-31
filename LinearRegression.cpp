#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma GCC optimization ("unroll-loops")
#define ll long long
using namespace std;
double cost(double c,double m,ll n,pair<int,int> p[])
{
    double cost=0;
    double pred;
    for(int i=0;i<n;i++)
    {
        pred=m*p[i].first+c;
        cost+=(p[i].second-pred)*(p[i].second-pred);
    }
    return cost/n;
}

double gradM(int n,double m,double c,pair<int,int>p[])
{
    double grad=0;
    for(int i=0;i<n;i++)
    {
        grad+=(p[i].second-m*p[i].first-c)*p[i].first;
    }
    grad/=n;
    return grad;
}

double gradC(int n,double m,double c,pair<int,int>p[])
{
    double grad=0;
    for(int i=0;i<n;i++)
    {
        grad+=(p[i].second-m*p[i].first-c);
    }
    grad/=n;
    return grad;
}
int main(void){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        pair<int,int> p[n];
        for(int i=0;i<n;i++)cin>>p[i].first>>p[i].second;
        double c=0;
        double m=0;         //line::y=m*x+c
        int iter=5000;
        int i=0;
        double alpha=0.02;
        while(i<iter)
        {
            m=m+gradM(n,m,c,p)*alpha;
            c=c+gradC(n,m,c,p)*alpha;
            i++;
        }
        cout<<"Cost is: "<<cost(c,m,n,p)<<"\n";
        cout<<"Slope of line is: "<<m<<" and y-intercept of line is "<<c;
    }
}
