#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double xT,x1,x2,x3,e1,e2,e3;
    cout<<"Enter X : ";
    cin>>xT;
    cout<<"Enter x1 : ";
    cin>>x1;
    cout<<"Enter x2 : ";
    cin>>x2;
    cout<<"Enter x3 : ";
    cin>>x3;
    e1=fabs(xT-x1);
    e2=fabs(xT-x2);
    e3=fabs(xT-x3);
    if(e1<e2 && e1<e3)
        cout<<"Output : "<<x1<<endl;
    if(e2<e1 && e2<e3)
        cout<<"Output : "<<x2<<endl;
    if(e3<e2 && e3<e1)
        cout<<"Output : "<<x3<<endl;

    return 0;
}
