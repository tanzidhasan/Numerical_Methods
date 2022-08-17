#include <bits/stdc++.h>

using namespace std;

double df(double f,double g)
{
    double r=(3*f)+(g/2);
    return r;
}

int main()
{
    double h,y,y0,y1,x0,x,k1,k2,k3,k4;
    cout<<"Enter x0 : ";
    cin>>x0;
    cout<<"Enter y0 : ";
    cin>>y0;
    y1=y0;
    cout<<"Enter x : ";
    cin>>x;
    cout<<"Enter y : ";
    cin>>y;
    for(;;)
    {
        cout<<endl<<endl<<"Enter h : ";
        cin>>h;
        int b;
        cout<<"1. 2nd Order Range-Kutta Method."<<endl<<"2. 4th Order Range-Kutta Method."<<endl<<"3. Compare."<<endl<<"4. Exit"<<endl<<"      Enter the option (1-4) : ";
        cin>>b;
        if(b>4)
            cout<<"Invalid Input."<<endl<<endl;
        if(b==4)
            break;
        switch(b)
        {
        case 1 :
            {
                cout<<endl<<"1. 2nd Order Range-Kutta Method."<<endl;
                int a=(x-x0)/h;
                double c=0;
                for(int i=0;i<a;i++)
                {
                    k1=h*df(x0+c,y0);
                    cout<<"k1 : "<<k1<<endl;
                    k2=h*df(x0+h+c,y0+k1);
                    cout<<"k2 : "<<k2<<endl;
                    y0=y0+(0.5)*(k1+k2);
                    cout<<"y"<<i+1<<" : "<<y0<<endl;
                    c=c+h;
                    cout<<endl;
                }

                cout<<"y("<<x<<") : "<<y0<<endl;
            }break;

        case 2 :
            {
                cout<<endl<<"2. 4th Order Range-Kutta Method."<<endl;
                int a=(x-x0)/h;
                double c=0;
                for(int i=0;i<a;i++)
                {
                    k1=h*df(x0+c,y1);
                    cout<<"k1 : "<<k1<<endl;
                    k2=h*df(x0+(h/2)+c,y1+(k1/2));
                    cout<<"k2 : "<<k2<<endl;
                    k3=h*df(x0+(h/2)+c,y1+(k2/2));
                    cout<<"k3 : "<<k3<<endl;
                    k4=h*df(x0+h+c,y1+k3);
                    cout<<"k4 : "<<k4<<endl;
                    y1=y1+(1.0/6)*(k1+(2*k2)+(2*k3)+k4);
                    cout<<"y"<<i+1<<" : "<<y1<<endl;
                    c=c+h;
                    cout<<endl;
                }
                cout<<"y("<<x<<") : "<<y1<<endl;
            }break;

        case 3 :
            {
                cout<<endl<<"3. Compare."<<endl;

                int a=(x-x0)/h;
                double c=0;
                for(int i=0;i<a;i++)
                {
                    k1=h*df(x0+c,y0);
                    cout<<"k1 : "<<k1<<endl;
                    k2=h*df(x0+h+c,y0+k1);
                    cout<<"k2 : "<<k2<<endl;
                    y0=y0+(0.5)*(k1+k2);
                    cout<<"y"<<i+1<<" : "<<y0<<endl;
                    c=c+h;
                    cout<<endl;
                }
                cout<<"2nd Order Range-Kutta Method : y("<<x<<") : "<<y0<<endl;
                cout<<"Error : "<<fabs(y-y0)<<endl<<endl;

                a=(x-x0)/h;
                c=0;
                for(int i=0;i<a;i++)
                {
                    k1=h*df(x0+c,y1);
                    cout<<"k1 : "<<k1<<endl;
                    k2=h*df(x0+(h/2)+c,y1+(k1/2));
                    cout<<"k2 : "<<k2<<endl;
                    k3=h*df(x0+(h/2)+c,y1+(k2/2));
                    cout<<"k3 : "<<k3<<endl;
                    k4=h*df(x0+h+c,y1+k3);
                    cout<<"k4 : "<<k4<<endl;
                    y1=y1+(1.0/6)*(k1+(2*k2)+(2*k3)+k4);
                    cout<<"y"<<i+1<<" : "<<y1<<endl;
                    c=c+h;
                    cout<<endl;
                }
                cout<<"4th Order Range-Kutta Method : y("<<x<<") : "<<y1<<endl<<endl;

                if(fabs(y-y0)<fabs(y-y1))
                    cout<<endl<<"2nd Order Range-Kutta Method is better than 4th Order Range-Kutta Method."<<endl;
                else
                    cout<<endl<<"4th Order Range-Kutta Method is better than 2nd Order Range-Kutta Method."<<endl;
            }
        }

    }
}
