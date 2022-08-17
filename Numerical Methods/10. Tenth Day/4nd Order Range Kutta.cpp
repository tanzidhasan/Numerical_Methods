#include <bits/stdc++.h>

using namespace std;

double df(double f,double g)
{
    double r=(3*f)+(g/2);
    return r;
}

int main()
{
    double h,y0,x0,x,k1,k2,k3,k4;
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
            k1=h*df(x0+c,y0);
            cout<<"k1 : "<<k1<<endl;
            k2=h*df(x0+(h/2)+c,y0+(k1/2));
            cout<<"k2 : "<<k2<<endl;
            k3=h*df(x0+(h/2)+c,y0+(k2/2));
            cout<<"k3 : "<<k3<<endl;
            k4=h*df(x0+h+c,y0+k3);
            cout<<"k4 : "<<k4<<endl;
            y0=y0+(1.0/6)*(k1+(2*k2)+(2*k3)+k4);
            cout<<"y0 : "<<y0<<endl;
            c=c+h;
            cout<<endl;
        }
        cout<<"y("<<x<<") : "<<y0<<endl;
    }

    return 0;

}
