#include <iostream>
#include <math.h>

using namespace std;

int i=1,j=1;

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
void bisection()
{
    int n;
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
        if(fabs(x2-x1)<0.00001)
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
    cout<<endl<<"Root : "<<x1<<endl;
}

void falseposition()
{
    int n;
    double a,a1,b,b1,e,x3,x4=0,y;
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
        a1=f(a,arr,n+1); b1=f(b,arr,n+1);
        x3=((a*b1)-(b*a1))/(b1-a1);
        y=f(x3,arr,n+1);
        cout<<j<<"\t\t"<<a<<"\t\t"<<b<<"\t\t"<<x3<<"\t\t"<<y<<endl;
        if(fabs(x4-x3)<0.0001)
            break;
        if((a1*y)<0)
            b=x3;
        if((a1*y)>0)
            a=x3;
        if(y==0)
            break;
        j++;
        x4=x3;
    }
    cout<<endl<<"Root : "<<x3<<endl;

}

void comparison()
{
    if(i>j)
        cout<<endl<<"False position lag "<<fabs(i-j)<<" steps behind Bisection."<<endl;
    if(i<j)
        cout<<endl<<"Bisection lag "<<fabs(i-j)<<" steps behind False position."<<endl;

}

int main()
{
    int a;
    for(;;)
    {
        cout<<"1. Bisection Method"<<endl<<"2. False Position Method"<<endl<<"3. Comparison"<<endl<<"4. Exit"<<endl<<"      Enter the option(1-4) : ";
        cin>>a;
        if(a>4)
            cout<<"Invalid input.";
        if(a==4)
            break;
        switch(a)
        {
        case 1 :
                {
                    cout<<endl<<"1. Bisection Method : "<<endl;
                    bisection();
                    cout<<endl<<endl;
                }break;

        case 2 :
                {
                    cout<<endl<<"2. False Position Method : "<<endl;
                    falseposition();
                    cout<<endl<<endl;
                }break;

        case 3 :
                {
                    cout<<endl<<"3. Comparison : "<<endl;
                    comparison();
                    cout<<endl<<endl;
                }break;
        }
    }


}
