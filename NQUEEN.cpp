#include<bits/stdc++.h>
using namespace std;

#define tr(c, it) \
for(auto it = c.begin(); it != c.end(); it++)
#define ll long long

//const int MAX=1e3 + 5;

bool isSafe(int ** arr,int i,int j,int n){

	for(int x=i-1;x>=0;x--){
		if(arr[x][j] == 1 )
			return false;
	}

	for(int x=i-1,y=j-1;x>=0 && y>=0;x--,y--){
		if(arr[x][y] == 1)
			return false;
	}

	for(int x=i-1,y=j+1;x>=0 && y<n;x--,y++ ){
		if(arr[x][y] == 1)
			return false;
	}

	return true;

}

void printer(int ** arr,int n){
	for(int i=0;i < n;i++){
		for(int j=0;j<n;j++){
            cout << arr[i][j] << " ";
		}
	}
	cout << endl;
}

void nqueen(int ** arr,int i,int n ){

	if(i == n){
		printer(arr,n);
		return ;
	}
	for(int j=0;j<n;j++){
		if(isSafe(arr,i,j,n)){

			arr[i][j] = 1;
			nqueen(arr,i+1,n);
			arr[i][j]=0;
		}
	}
}

int main(){

  	int n;
  	cin >> n;

  	int ** arr = new int*[n];
  	for(int i=0;i<n;i++){
  		arr[i] = new int[n];
  		for(int j=0;j<n;j++){
  			arr[i][j]  = 0;
  		}
  	}

  	nqueen(arr,0,n);

	return 0;
}



/*
check for corner cases(n == 1?)
see the constraint
read the highlighted text again
*/
