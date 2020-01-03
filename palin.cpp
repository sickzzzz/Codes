https://mega.nz/#!tvpzxaDD!-Z8x2tf9lhwRwgVXEAIIYZmLkaUM8aPvL9u2ypSylz8//MEHNAT
#include<bits/stdc++.h>
using namespace std;

#define tr(c, it) \
for(auto it = c.begin(); it != c.end(); it++)
#define ll long long

//const int MAX=1e3 + 5;

int main(){

    int q;
    cin >> q;

    for(int i=0;i<q;i++){
        string s;
        cin >> s;

        map <char,vector <int>> mp;
        map <char,vector <int>> :: iterator it;

        for(int i=0;i<s.length();i++){
            mp[s[i]].push_back(i);
        }
        /*
        for(it=mp.begin();it!=mp.end();it++){
            cout << it->first <<" ";
            vector <int> x=it->second;
            for(int i=0;i<x.size();i++){
                cout << x[i] << " ";
            }
            cout <<  endl;
        }
        */
        int c=0;
        char o;
        bool flag=false;
        for(it=mp.begin();it!=mp.end();it++){
            vector <int> x=it->second;
            if(x.size()%2==1){
                o=it->first;
                c++;
                flag=true;
            }
        }
        if(c>=2){
            cout << -1 ;

        }else{
            int arr[s.length()];
            if(flag){
                arr[s.length()/2]=mp[o].back();
                mp[o].pop_back();
            }

            int i=0;
            for(it=mp.begin();it!=mp.end();it++){
                vector <int> x=it->second;
                for(int j=0;j<x.size();j+=2){
                    arr[i]=x[j];
                    arr[s.length()-i-1]=x[j+1];
                    i++;
                }
            }

            for(int j=0;j<s.length();j++){
                cout << arr[j]+1 <<" ";
            }

        }
        cout << endl;




    }



    return 0;
}



/*
check for corner cases(n == 1?)
see the constraint
read the highlighted text again
*/
