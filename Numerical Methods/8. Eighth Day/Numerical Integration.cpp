#include <bits/stdc++.h>

using namespace std;

double f(double x)
{
    double r=(1.0/(1+x));
    return r;
}

double trapezoidal(int m,double v[],double  k)
{
    double s=v[0]+v[m];
    double sum=0;
    for(int i=1;i<m;i++)
        sum=sum+v[i];
    sum=sum*2;
    sum=sum+s;
    sum=(k/2.0)*sum;

    return sum;
}

double simpson_o_t(int n,double u[],double l)
{
    double s=u[0]+u[n];
    double sum=0;
    for(int i=1;i<n;i++)
    {
        if(i%2==0)
            sum=sum+(2*u[i]);
        else
            sum=sum+(4*u[i]);
    }
    sum=sum+s;
    sum=(l/3.0)*sum;

    return sum;

}

double simpson_t_e(int o,double w[],double p)
{
    double s=w[0]+w[o];
    double sum=0;
    for(int i=1;i<o;i++)
    {
        if(i%3==0)
            sum=sum+(2*w[i]);
        else
            sum=sum+(3*w[i]);
    }
    sum=sum+s;
    sum=(((3.0)*p*sum)/(8.0));

    return sum;
}

int main()
{

    for(;;)
    {
        double a,b,h;
        int g;
        cout<<"Enter the lower limit & upper limit : ";
        cin>>a>>b;
        cout<<"Enter the difference (h) : ";
        cin>>h;
        g=round((b-a)/h);
        double x[g+1],y[g+1];
        for(int i=0;i<=g;i++)
        {
            x[i]=a+(i*h);
            y[i]=f(x[i]);
        }

        double j=(log(1+b))-(log(1+a));
        double j1,j2,j3;
        int d;
        cout<<endl<<"1. Trapezoidal Rule."<<endl<<"2. Simpson's 1/3 Rule."<<endl<<"3. Simpson's 3/8 Rule."<<endl<<"4. Compare."<<endl<<"5. Exit."<<endl<<ends<<"Enter the option(1-5) : ";
        cin>>d;
        if(d>5)
            cout<<endl<<"Invalid input."<<endl<<endl;
        if(d==5)
            break;
        switch(d)
        {
        case 1:
               {
                   cout<<endl<<"1. Trapezoidal Rule : "<<endl;
                   j1=trapezoidal(g,y,h);
                   cout<<"Value : "<<j1<<endl;
                   cout<<"Error : "<<fabs(j1-j)<<endl<<endl<<endl<<endl;
               }break;

        case 2:
               {
                   cout<<endl<<"2. Simpson's 1/3 Rule : "<<endl;
                   j2=simpson_o_t(g,y,h);
                   cout<<"Value : "<<j2<<endl;
                   cout<<"Error : "<<fabs(j2-j)<<endl<<endl<<endl<<endl;
               }break;
        case 3:
               {
                   cout<<endl<<"3. Simpson's 3/8 Rule : "<<endl;
                   j3=simpson_t_e(g,y,h);
                   cout<<"Value : "<<j3<<endl;
                   cout<<"Error : "<<fabs(j3-j)<<endl<<endl<<endl<<endl;
               }break;
        case 4:
               {
                   cout<<endl<<"4. Compare : "<<endl<<endl;
                   cout<<"Calculated Value : "<<j<<endl;
                   j1=trapezoidal(g,y,h);
                   cout<<"Trapezoidal Rule : "<<j1<<" : |"<<j<<"-"<<j1<<"| = "<<fabs(j-j1)<<endl;
                   j2=simpson_o_t(g,y,h);
                   cout<<"Simpson's 1/3 Rule : "<<j2<<" : |"<<j<<"-"<<j2<<"| = "<<fabs(j-j2)<<endl;
                   j3=simpson_t_e(g,y,h);
                   cout<<"Simpson's 3/8 Rule : "<<j3<<" : |"<<j<<"-"<<j3<<"| = "<<fabs(j-j3)<<endl;

                   if((fabs(j1-j)<fabs(j2-j)) && (fabs(j1-j)<fabs(j3-j)))
                      cout<<endl<<"Trapezoidal is the best rule."<<endl;

                   if((fabs(j2-j)<fabs(j1-j)) && (fabs(j2-j)<fabs(j3-j)))
                      cout<<endl<<"Simpson's 1/3 is the best rule."<<endl;

                   if((fabs(j3-j)<fabs(j1-j)) && (fabs(j3-j)<fabs(j2-j)))
                      cout<<endl<<"Simpson's 3/8 is the best rule."<<endl;
                   cout<<endl<<endl<<endl;
               }break;
       }
    }

}

