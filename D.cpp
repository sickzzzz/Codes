#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin>>n;
    long a[n];
    map><long ,int>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
    }
    map<long,int>::iterator it;
    for(it=m.begin();it!=v.end();it++)
    {
        if((it->second)%2!=0)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

    return 0;
}
