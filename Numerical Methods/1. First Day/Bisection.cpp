#include <iostream>
#include <math.h>

using namespace std;

double f(double d,double c[],int r)
{
    int s=r-1;
    double t=0;
    for(int i=0;i<r;i++)
    {
        t=t+(c[i]*pow(d,s--));
    }
    return t;
}

int main()
{
    int i=1,n;
    double a,b,e,x1,x2=0,y;
    cout<<"Enter the power of equation : ";
    cin>>n;
    double arr[n+1];
    int m=n;
    for(int i=0;i<n+1;i++)
    {
        cout<<"Coefficient of x^"<<m--<<" : ";
        cin>>arr[i];
    }
    for(;;)
    {
        cout<<"Enter a : ";
        cin>>a;
        cout<<"Enter b : ";
        cin>>b;
        e=f(a,arr,n+1)*f(b,arr,n+1);
        if(e<0)
            break;
        else
            cout<<"Wrong input."<<endl;
    }
    cout<<endl<<"i\t\t"<<"a\t\t"<<"b\t\t"<<"x\t\t"<<"y"<<endl<<endl;
    for(;;)
    {
        x1=(a+b)/2;
        y=f(x1,arr,n+1);
        cout<<i<<"\t\t"<<a<<"\t\t"<<b<<"\t\t"<<x1<<"\t\t"<<y<<endl;
        if(fabs(x2-x1)<0.001)
            break;
        if((f(a,arr,n+1)*y)<0)
            b=x1;
        if((f(a,arr,n+1)*y)>0)
            a=x1;
        if(y==0)
            break;
        i++;
        x2=x1;
    }
    cout<<endl<<"Value : "<<x1<<endl;

}
