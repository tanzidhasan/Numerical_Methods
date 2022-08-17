#include <bits/stdc++.h>

using namespace std;

double df(double f,double g)
{
    double r=(f-(g*g));
    return r;
}

int main()
{
    double x[200],y[200],xd;
    cout<<"Enter the x0 : ";
    cin>>x[0];
    cout<<"Enter the y0 : ";
    cin>>y[0];

    cout<<"Enter the desire x : ";
    cin>>xd;


    for(;;)
    {
        double h;
        cout<<endl<<endl<<"Enter the value of h (Enter 0 to break ) : ";
        cin>>h;

        if(h==0)
            break;

        int g=(xd-x[0])/h;

        for(int i=0;i<=g;i++)
        {
            x[i+1]=x[i]+h;
            y[i+1]=(y[i]+(h*df(x[i],y[i])));

        }
        cout<<endl<<"Value : "<<y[g]<<endl;
    }
}

