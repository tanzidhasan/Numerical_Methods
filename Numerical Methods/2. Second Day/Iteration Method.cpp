#include <iostream>
#include <math.h>

using namespace std;

double df(int e)
{
    double s=cos(e);
    return s;
}

double f(double d)
{
    double t=sin(d)+.5;
    return t;
}

int main()
{
    int i=1,n=1;
    double a,x1,x2=0,b;
    for(;;)
    {
        a=df(n);
        if(fabs(a)<1)
            break;
        else
            n++;
    }
    b=n;
    cout<<endl<<"i\t\t"<<"x\t\t"<<"Q(x)"<<endl<<endl;
    for(;;)
    {
        x1=f(b);
        cout<<i<<"\t\t"<<b<<"\t\t"<<x1<<endl;
        if(fabs(x1-b)<0.001)
            break;
        else
            b=x1;
        i++;
    }
    cout<<endl<<"Root : "<<x1<<endl;

}

