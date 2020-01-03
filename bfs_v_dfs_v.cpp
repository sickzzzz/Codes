//MEHNAT
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(c) c.begin(), c.end()
#define tr(c, it) \
for(auto it = c.begin(); it != c.end(); it++)
#define repo(i,o,e) for(int i = o ; i < e ; i++)
#define rep(n) for(int i = 0 ; i < n ; i++)

const int MAX=1e5 + 5;
int n,m;
vector <int> v[MAX];
bool vis[MAX]={0};
set <int> q;

void dfs(int x){
    int a;
    vis[x]=1;
    q.insert(x);
    while(!q.empty()){
        a= *(q.begin());
        q.erase(a);
        cout<<a<<" ";
        for(int i=0;i<v[a].size();i++){
            if(!vis[v[a][i]]){
                q.insert(v[a][i]);
                vis[v[a][i]]=1;
            }
        }
    }
}

int main(){
    cin>>n>>m;
    int x,y;
    rep(m){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1);

    return 0;
}

/*
check for corner cases(n == 1?)
see the constraint
read the highlighted text again
*/





