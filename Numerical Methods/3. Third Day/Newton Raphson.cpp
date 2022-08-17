#include <iostream>
#include <math.h>

using namespace std;

double df(double e)
{
    double s=(3*e*e)-(4*e)+3;
    return s;
}

double f(double d)
{
    double t=(d*d*d)-(2*d*d)+(3*d)-5;
    return t;
}

int main()
{
    int i=1;
    double a,x1,x2=0,b=2.0;
    cout<<endl<<"i\t\t"<<"x\t\t"<<"Q(x)"<<endl<<endl;
    for(;;)
    {
        x1=b-(f(b)/df(b));
        cout<<i<<"\t\t"<<b<<"\t\t"<<x1<<endl;
        if(fabs(x1-x2)<0.0001)
            break;
        else
            b=x1;
        x2=x1;
        i++;
    }
    cout<<endl<<"Root : "<<x1<<endl;

}


