#include <bits/stdc++.h>

using namespace std;

double f(double b0,double b1,double x)
{
    double y=exp(b0+(b1*x));
    return y;
}

int main()
{
    int n;
    double sumx=0,sumy=0,sumxx=0,sumxy=0;
    cout<<"How many element you want to input : ";
    cin>>n;
    double x[n];
    double y[n];
    for(int i=1;i<=n;i++)
    {
        cout<<"x1 : ";
        cin>>x[i];
        sumx=sumx+x[i];
        sumxx=sumxx+(x[i]*x[i]);
        cout<<"y1 : ";
        cin>>y[i];
        cout<<endl;
        sumy=sumy+log(y[i]);
        sumxy=sumxy+(x[i]*log(y[i]));
    }

    double d=((n*sumxx)-(sumx*sumx));
    double a0=exp(((sumxx*sumy)-(sumx*sumxy))/d);
    double a1=((sumxy*n)-(sumx*sumy))/d;

    cout<<"a0 : "<<a0<<ends<<ends<<"a1 : "<<a1<<endl;

    double err[n];

    cout<<endl<<"Errors : "<<endl;
    for(int i=1;i<=n;i++)
    {
        err[i]=y[i]-f(log(a0),a1,x[i]);
        cout<<"For "<<x[i]<<", "<<"error : "<<err[i]<<endl;
    }



    return 0;
}

