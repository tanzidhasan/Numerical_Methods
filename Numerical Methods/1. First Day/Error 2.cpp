#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double x1,x2,x3,y1,y2,y3,x,y;
    cout<<"Enter x1 : ";
    cin>>x1;
    x1=sqrt(x1);
    cout<<"Enter x2 : ";
    cin>>x2;
    x2=sqrt(x2);
    cout<<"Enter x3 : ";
    cin>>x3;
    x3=sqrt(x3);
    cout<<"Enter y1 : ";
    cin>>y1;
    cout<<"Enter y2 : ";
    cin>>y2;
    cout<<"Enter y2 : ";
    cin>>y3;
    x=x1+x2+x3;
    y=y1+y2+y3;
    double eA=fabs(x-y);
    double eR=eA/x;
    double eP=eR*100;

    cout<<"Absolute Error : "<<eA<<endl<<"Relative Error : "<<eR<<endl<<"Percentage Error : "<<eP<<endl;

    return 0;
}
