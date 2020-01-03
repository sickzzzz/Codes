
#include<bits/stdc++.h>
using namespace std;

#define tr(c, it) \
for(auto it = c.begin(); it != c.end(); it++)
#define ll long long

//const int MAX=1e3 + 5;

void merge_sort(int *a,int n){
    if(n==1)
        return ;
    int mid=n/2;
    int i=0,j=mid,k=0;
    merge_sort(a,n/2);
    merge_sort(a+mid,(n-mid));
    int temp[n];

    while(i<mid && j<n){
        if(a[i]<a[j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
        }
    }
    while(i < mid)
        temp[k++]=a[i++];
    while(j < n)
        temp[k++]=a[j++];

    for(int i=0;i<n;i++){
        a[i]=temp[i];
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int a[n];

        for(int i=0;i<n;i++)
            cin >> a[i];

        
        for(int i=0;i<n;i++){
            cout << a[i] << " " ;
        }
    }
    return 0;
}



/*
check for corner cases(n == 1?)
see the constraint
read the highlighted text again
*/
