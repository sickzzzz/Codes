//MEHNAT
#include<bits/stdc++.h>
using namespace std;

#define tr(c, it) \
for(auto it = c.begin(); it != c.end(); it++)
#define ll long long

//const int MAX=1e3 + 5;

bool flag=0;


int main(){
    int n;
    string s="";
    cin>>n>>s;
    int a[n];
    for(int i=1;i<10;i++){
        cin>>a[i];
    }

    stack <pair<int,int> > st;

    pair <int,int> p;
    p.first=0;
    p.second=0;
    int b;
    for(int i=n-1;i>=0;i--){
        b=((int) s[i]) - 48;
        if(b<a[b] && !flag){
            p.second=i;
            flag=1;
        }
        if(b>=a[b] && flag){
            p.first=i+1;
            st.push(p);
            flag=0;
        }
        if(b<a[b] && flag && i==0){
            p.first=0;
            st.push(p);
            flag=0;
        }
    }

    /*
    for(int i=0;st.size();i++){
        q=st.top();
        st.pop();
        cout<<q.first<<" "<<q.second<<endl;
    }*/

    if(st.empty()){
        cout<<s;
    }
    else{
        pair <int,int> q;
        q=st.top();
        for(int i=q.first;i<=q.second;i++){
            int b=((int) s[i]) - 48;
            s[i]=a[b] + 48;
        }
        cout<<s;
    }


    return 0;
}

/*
check for corner cases(n == 1?)
see the constraint
read the highlighted text again
*/
