//MEHNAT
#include<bits/stdc++.h>
using namespace std;

#define tr(c, it) \
for(auto it = c.begin(); it != c.end(); it++)
#define ll long long

//const int MAX=1e3 + 5;

int main(){

    int n;
    cin >> n;

    int ** arr= new int*[n];

    for(int i=0;i<n;i++){
        cout<<"Enter the size of the row"<<endl;
        int x;
        cin >> x;
        arr[i]=new int[x + 1];
        arr[i][0]=x;
        for(int j=1;j<=x;j++){
            cin >> arr[i][j];
        }
    }

    cout << "The array input " << endl;

    for(int i=0;i<n;i++){
        for(int j=1;j<=arr[i][0];j++){
            cout << arr[i][j] ;
        }
        cout << endl;
    }

    for(int i=0;i<n;i++){
        delete arr[i];
    }

    delete [] arr;

    return 0;
}

/*
check for corner cases(n == 1?)
see the constraint
read the highlighted text again
*/
