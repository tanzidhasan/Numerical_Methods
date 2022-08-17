#include<bits/stdc++.h>

using namespace std;

struct node
{
    long long value;
    node *next[ 26 ];
    node()
    {
        value = 0;
        for(int i = 0 ; i < 26 ; ++i)
        {
            next[ i ] = NULL;
        }
    }
}*root;

long long ans;

void insert(string str)
{
    node *curr = root;
    for(int i = 0 ; str[i] ; ++i)
    {
        if( curr->next[ str[ i ] - 'a' ] == NULL)
        {
            curr->next[ str[ i ] - 'a' ] = new node();
        }
        curr = curr->next[ str[ i ] - 'a' ];
        ++curr->value;
    }
}


void searchAns(string str)
{
    ans = 0;
    node *curr = root;
    int len = str.size();
    for(int i = 0 ; str[ i ] ; ++i)
    {
        curr = curr->next[ str[ i ] - 'a' ];
        if( !curr->value )
        {
            ans = 0;
        }
        if( i == len - 1 )
        {
            ans = curr->value;
        }
    }
}


int main()
{
    string str, ty;
    long long test;

    cin >> test;

    root = new node();

    while(test--)
    {
        cin >> ty >> str;
        if( ty == "add" )
        {
            insert(str);
        }
        else
        {
            searchAns(str);
            cout << ans << endl;
        }
    }

    return 0;
}
