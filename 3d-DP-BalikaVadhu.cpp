#include<bits/stdc++.h>
using namespace std;
#define ll long long


int lcsk(char * a , char * b , int n , int  m , int ***dp , int k){

	if((n == 0 || m == 0) && k != 0 )
		return INT_MIN;

	if(k == 0)
		return 0;

	if(dp[n][m][k] != -1)
		return dp[n][m][k];

	int res;

	if(a[0] == b[0]){

		int res1 = a[0] + lcsk(a + 1 , b + 1 , n - 1 , m - 1 , dp , k - 1 );

		int res2 = max(lcsk(a , b + 1 , n , m - 1 , dp , k) , lcsk(a + 1 , b , n - 1 , m ,dp , k) );

		res = max(res1 , res2);
	}
	else{

		res = max(lcsk(a , b + 1 , n , m - 1 , dp , k) , lcsk(a + 1 , b , n - 1 , m ,dp , k) );

	}

	dp[n][m][k] = res;

	return res;

}	

int main(){
	
	int t;
	cin >> t;

	while(t--){

		int k;

		string a , b;
		cin >> a >> b >> k;

		int n = a.length() , m = b.length() ;

		char * a_ = new char[n+1];

		strcpy(a_  , a.c_str());

		char * b_ = new char[m+1];

		strcpy(b_ , b.c_str());

		int *** dp = new int**[n+1];

		for(int i = 0 ; i <= n ; i++){

			dp[i] = new int*[m+1];

			for(int j = 0 ; j <= m ; j++){

				dp[i][j] = new int[k+1];

				for(int l = 0 ; l <= k ; l++)
					dp[i][j][l] = -1;

			}

		}

		for(int i = 0 ; i <= n ; i++)
			dp[i][0][0] = 0;

		for(int i = 0 ; i <= m ; i++)
			dp[0][i][0] = 0;

		for(int i = 0 ; i <= k ; i++)
			dp[0][0][i] = 0;


		int result = lcsk(a_ , b_ , n , m , dp , k);

		if(result > 0)
			cout << result << endl;
		else 
			cout << 0 << endl;
	}	

	return 0;
}



 