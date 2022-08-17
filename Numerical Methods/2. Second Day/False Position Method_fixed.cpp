#include <iostream>
#include <math.h>

using namespace std;

double f(double d)
{
    double t=0;
    t=t+((d*log10(d))-1.2);
    return t;
}

int main()
{
    int i=1,n;
    double a,a1,b,b1,e,x1,x2=0,y;

    for(;;)
    {
        cout<<"Enter a : ";
        cin>>a;
        cout<<"Enter b : ";
        cin>>b;
        e=f(a)*f(b);
        if(e<0)
            break;
        else
            cout<<"Wrong input."<<endl;
    }
    cout<<endl<<"i\t\t"<<"a\t\t"<<"b\t\t"<<"x\t\t"<<"y"<<endl<<endl;
    for(;;)
    {
        a1=f(a); b1=f(b);
        x1=((a*b1)-(b*a1))/(b1-a1);
        y=f(x1);
        cout<<i<<"\t\t"<<a<<"\t\t"<<b<<"\t\t"<<x1<<"\t\t"<<y<<endl;
        if(fabs(x2-x1)<0.001)
            break;
        if((a1*y)<0)
            b=x1;
        if((a1*y)>0)
            a=x1;
        if(y==0)
            break;
        i++;
        x2=x1;
    }
    cout<<endl<<"Root : "<<x1<<endl;

}

