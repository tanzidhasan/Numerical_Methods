#include <bits/stdc++.h>

using namespace std;

double a[1000],b[1000];
int main()
{
    double c[100];
    int n;
    cout<<"Enter the power of equation : ";
    cin>>n;
    double arr[n+1];
    int p=n;
    for(int i=0;i<n+1;i++)
    {
        cout<<"Coefficient of x^"<<p--<<" : ";
        cin>>arr[i];
    }
    p=n-1;
    for(int i=1;i<n+1;i++)
    {
        a[i]=-(arr[p]/arr[n]);
        p--;
    }
    b[1]=1;
    int k,l,m;
    for(int i=2;;i++)
    {
        k=i-1;
        for( int j=1;j<i;j++)
        {
            b[i]=b[i]+(a[j]*b[k]);
            k--;
        }
        l=i;
        if(i==int(pow(3,n)))
           break;
    }
    for(int i=1;i<l;i++)
    {
        c[i]=b[i]/b[i+1];
        if(i>1)
            if(fabs(c[i]-c[i-1])<0.001 && fabs(c[i]-c[i-1])!=0)
            {
                m=i;
                break;
            }
    }
    cout<<"i\t\tb[n]\t\tb[n+1]\t\tb[n]/b[n+1]"<<endl<<"------------------------------------------------------------"<<endl;
    for(int i=1;i<=m;i++)
        cout<<i<<"\t\t"<<b[i]<<"\t\t"<<b[i+1]<<"\t\t"<<c[i]<<endl;

    cout<<endl<<"Root : "<<c[m]<<endl;

}
