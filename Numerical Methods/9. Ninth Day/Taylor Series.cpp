#include <bits/stdc++.h>

using namespace std;

int fact(int a)
{
    if(a==0)
        return 1;
    else
        return (a*fact(a-1));
}

double df1(double f,double g)
{
    double r=(f-(g*g));
    return r;
}

double df2(double f,double g)
{
    double r=(1-(2*g*df1(f,g)));
    return r;
}

double df3(double f,double g)
{
    double r=-(2*g*df2(f,g))-(2*df1(f,g)*df1(f,g));
    return r;
}

double df4(double f,double g)
{
    double r=-(2*g*df3(f,g))-(6*df1(f,g)*df2(f,g));
    return r;
}

double df5(double f,double g)
{
    double r=-(2*g*df4(f,g))-(6*df1(f,g)*df3(f,g))-(6*df2(f,g)*df2(f,g));
    return r;
}

int main()
{
    double x0,xd,y[10];
    cout<<"Enter the x0 : ";
    cin>>x0;
    cout<<"Enter the y0 : ";
    cin>>y[0];

    cout<<"Enter the desire x : ";
    cin>>xd;

    y[1]=df1(x0,y[0]);
    y[2]=df2(x0,y[0]);
    y[3]=df3(x0,y[0]);
    y[4]=df4(x0,y[0]);
    y[5]=df5(x0,y[0]);

    double sum=1;

    for(int i=1;i<=5;i++)
        sum=sum+((pow(xd,i)*y[i])/fact(i));

    cout<<endl<<"Value : "<<sum<<endl;
}
