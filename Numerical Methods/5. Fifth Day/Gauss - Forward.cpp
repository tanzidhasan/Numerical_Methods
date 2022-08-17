#include <bits/stdc++.h>

using namespace std;

int fact(int n)
{
    int multi=1;
    for(int i=1;i<=n;i++)
        multi=multi*i;
    return multi;
}

int main()
{
    int n;
    double m,h;
    cout<<"How many elements you want to input : ";
    cin>>n;
    double a[n];
    double b[n][n];
    double q[n];
    cout<<"Enter x and corresponding y : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"x"<<i<<" : ";
        cin>>a[i];
        cout<<"y"<<i<<" : ";
        cin>>b[0][i];
    }
    cout<<"For which x you want to determine the value : ";
    cin>>m;

    double sum=0;
    h=a[1]-a[0];
    int r=(n/2);
    cout<<r<<endl;
    double p=((m-a[r])*1.0)/h;
    for(int i=0;i<n;i++)
        for(int j=0;j<n-i;j++)
            b[i+1][j]=b[i][j+1]-b[i][j];

    q[0]=1;q[1]=p;
    double g=p;
    for(int i=2;i<n;i++)
    {
        g=g*(p-i+1);
        q[i]=(g*1.0)/fact(i);
    }

    int c=0;

    for(int i=0;i<n;i++)
    {
        c++;
        sum=sum+(q[i]*b[i][r]);
        if(c%2==0)
            r--;
    }
    cout<<"Answer : "<<sum<<endl;
}
