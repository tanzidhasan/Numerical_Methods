#include <bits/stdc++.h>

using namespace std;

int fact(int n)
{
    int multi=1;
    for(int i=1;i<=n;i++)
        multi=multi*i;
    return multi;
}

void inter_forward()
{
    int n;
    double m,h;
    cout<<"How many elements you want to input : ";
    cin>>n;
    double a[n];
    double b[n][n];
    double q[n];
    cout<<"Enter x and corresponding y : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"x"<<i<<" : ";
        cin>>a[i];
        cout<<"y"<<i<<" : ";
        cin>>b[0][i];
    }
    cout<<"For which x you want to determine the value : ";
    cin>>m;
    double sum=0;
    h=a[1]-a[0];
    double p=((m-a[0])*1.0)/h;
    for(int i=0;i<n;i++)
        for(int j=0;j<n-i;j++)
            b[i+1][j]=b[i][j+1]-b[i][j];

    q[0]=1;q[1]=p;
    double g=p;
    for(int i=2;i<n;i++)
    {
        g=g*(p-i+1);
        q[i]=(g*1.0)/fact(i);
    }

    for(int i=0;i<n;i++)
    {
        sum=sum+(q[i]*b[i][0]);
    }
    cout<<"Answer : "<<sum<<endl;
}

void inter_backward()
{
    int n;
    double m,h;
    cout<<"How many elements you want to input : ";
    cin>>n;
    double a[n];
    double b[n][n];
    double q[n];
    cout<<"Enter x and corresponding y : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"x"<<i<<" : ";
        cin>>a[i];
        cout<<"y"<<i<<" : ";
        cin>>b[0][i];
    }
    cout<<"For which x you want to determine the value : ";
    cin>>m;
    double sum=0;
    h=a[1]-a[0];
    double p=((m-a[n-1])*1.0)/h;
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            b[i+1][j+1]=b[i][j+1]-b[i][j];

    q[0]=1;q[1]=p;
    double g=p;
    for(int i=2;i<n;i++)
    {
        g=g*(p-i+1);
        q[i]=(g*1.0)/fact(i);
    }

    for(int i=0;i<n;i++)
        sum=sum+(q[i]*b[i][n-1]);

    cout<<"Answer : "<<sum<<endl;
}

int main()
{
    int k;
    for(;;)
    {
        cout<<"1. Interpolation Forward Method."<<endl<<"2. Interpolation Backward Method."<<endl<<"3. Exit."<<endl<<"    Enter the option(1-3) : ";
        cin>>k;
        if(k>3)
            cout<<"Invalid input."<<endl<<endl;
        if(k==3)
            break;
        switch(k)
        {
        case 1 :
                {
                    cout<<endl<<"1. Interpolation Forward Method : "<<endl;
                    inter_forward();
                    cout<<endl<<endl;
                }break;

        case 2 :
                {
                    cout<<endl<<"2. Interpolation Backward Method : "<<endl;
                    inter_backward();
                    cout<<endl<<endl;
                }
        }
    }
    return 0;
}
