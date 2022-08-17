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
    double a,b,e,x1,x2=0,y;
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
        x1=(a+b)/2;
        y=f(x1);
        cout<<i<<"\t\t"<<a<<"\t\t"<<b<<"\t\t"<<x1<<"\t\t"<<y<<endl;
        if(fabs(x2-x1)<0.001)
            break;
        if((f(a)*y)<0)
            b=x1;
        if((f(a)*y)>0)
            a=x1;
        if(y==0)
            break;
        i++;
        x2=x1;
    }
    cout<<endl<<"Value : "<<x1<<endl;

}
