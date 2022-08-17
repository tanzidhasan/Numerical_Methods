#include <bits/stdc++.h>

using namespace std;

double df(double f,double g)
{
    double r=(3*f)+(g/2);
    return r;
}

int main()
{
    double h,y0,y1,x0,x,k1,k2;
    cout<<"Enter x0 : ";
    cin>>x0;
    cout<<"Enter y0 : ";
    cin>>y0;
    cout<<"Enter x : ";
    cin>>x;

    for(;;)
    {
        cout<<endl<<"Enter h (Enter 0 to break) : ";
        cin>>h;
        if(h==0)
            break;
        int a=(x-x0)/h;
        double c=0;
        for(int i=0;i<a;i++)
        {
            k1=df(x0+c,y0);
            y1=y0+(h*df(x0+c,y0));
            k2=df(x0+c+h,y1);
            y0=y0+(h/2)*(k1+k2);
            c=c+h;
            cout<<"y"<<i+1<<" : "<<y0<<endl;
            cout<<endl;
        }
        cout<<"y("<<x<<") : "<<y0<<endl;
    }

    return 0;

}

