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

    for(int i=0;i<n;i++)
        for(int j=0;j<n-i;j++)
            b[i+1][j]=b[i][j+1]-b[i][j];

    h=a[1]-a[0];
    double p=.5-((b[1][0])/b[2][0]);

    double x=a[0]+(p*h);

    if(x<=a[n/2])
        {
            double sum1=0;
    double h1=a[1]-a[0];
    double p1=((x-a[0])*1.0)/h1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n-i;j++)
            b[i+1][j]=b[i][j+1]-b[i][j];

    double q1[n];
    q1[0]=1;q1[1]=p1;
    double g1=p1;
    for(int i=2;i<n;i++)
    {
        g1=g1*(p1-i+1);
        q1[i]=(g1*1.0)/fact(i);
    }

    for(int i=0;i<n;i++)
    {
        sum1=sum1+(q1[i]*b[i][0]);
    }
    cout<<"Answer : "<<sum1<<endl;
        }

    if(x>a[n/2])
        {
            double sum2=0;
    double h2=a[1]-a[0];
    double p2=((x-a[n-1])*1.0)/h2;
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            b[i+1][j+1]=b[i][j+1]-b[i][j];

    double q2[n];
    q2[0]=1;q2[1]=p2;
    double g2=p2;
    for(int i=2;i<n;i++)
    {
        g2=g2*(p+i-1);
        q2[i]=(g2*1.0)/fact(i);
    }

    for(int i=0;i<n;i++)
        sum2=sum2+(q2[i]*b[i][n-1]);

    cout<<"Answer : "<<sum2<<endl;
        }



    return 0;

}
