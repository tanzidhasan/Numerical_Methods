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
    int r=(n/2);
    h=a[1]-a[0];
    double p=((m-a[r])*1.0)/h;
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            b[i+1][j+1]=b[i][j+1]-b[i][j];

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
        if(c%2==0)
            r--;
        sum=sum+(q[i]*b[i][r]);

    }

    cout<<"Answer : "<<sum<<endl;

    return 0;
}
