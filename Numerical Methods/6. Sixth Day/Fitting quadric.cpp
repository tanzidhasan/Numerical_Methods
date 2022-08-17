#include <bits/stdc++.h>

using namespace std;

double f(double b0,double b1,double x)
{
    double y=b0+(b1*x);
    return y;
}

int main()
{
    int n;
    double sumx=0,sumy=0,sumxx=0,sumxy=0,sumxxx=0,sumxxxx=0,sumxxy=0;
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
        sumxxx=sumxxx+(pow(x[i],3));
        sumxxxx=sumxxxx+(pow(x[i],4));
        cout<<"y1 : ";
        cin>>y[i];
        cout<<endl;
        sumy=sumy+y[i];
        sumxy=sumxy+(x[i]*y[i]);
        sumxxy=sumxxy+(x[i]*x[i]*y[i]);
    }

    for(int i=1;i<=n;i++)
    {
        cout<<x[i]<<ends<<ends<<y[i]<<ends<<ends<<(x[i]*x[i])<<ends<<ends<<(pow(x[i],3))<<ends<<ends<<(pow(x[i],4))<<ends<<ends<<(x[i]*y[i])<<ends<<ends<<(x[i]*x[i]*y[i])<<endl;
    }
    cout<<endl<<sumx<<ends<<ends<<sumy<<ends<<ends<<sumxx<<ends<<ends<<sumxxx<<ends<<ends<<sumxxxx<<ends<<ends<<sumxy<<ends<<ends<<sumxxy<<endl;

    double d=(n*((sumxx*sumxxxx)-(sumxxx*sumxxx)))-(sumx*((sumx*sumxxxx)-(sumxx*sumxxx)))+(sumxx*((sumx*sumxxx)-(sumxx*sumxx)));
    double a0=((sumy*((sumxx*sumxxxx)-(sumxxx*sumxxx)))-(sumx*((sumxy*sumxxxx)-(sumxxy*sumxxx)))+(sumxx*((sumxy*sumxxx)-(sumxxy*sumxx))))/(d*1.0);
    double a1=((n*((sumxy*sumxxxx)-(sumxxy*sumxxx)))-(sumy*((sumx*sumxxxx)-(sumxx*sumxxx)))+(sumxx*((sumx*sumxxy)-(sumxy*sumxx))))/(d*1.0);
    double a2=((n*((sumxx*sumxxy)-(sumxxx*sumxy)))-(sumx*((sumx*sumxxy)-(sumxx*sumxy)))+(sumy*((sumx*sumxxx)-(sumxx*sumxx))))/(d*1.0);

    cout<<"a0 : "<<a0<<ends<<"a1 : "<<a1<<ends<<"a2 : "<<a2<<endl;

    double err[n];

    cout<<endl<<"Error : "<<endl;
    for(int i=1;i<=n;i++)
    {
        err[i]=y[i]-f(a0,a1,x[i]);
        cout<<"For "<<x[i]<<", "<<"error : "<<err[i]<<endl;
    }



    return 0;
}

