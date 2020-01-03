	#include<bits/stdc++.h>
	using namespace std;
	#define ld long double
	#define ll long long
	#define loop(i,x,y) for(ll i=x;i<y;i++)
	#define pb push_back
	#define S second
	#define F first

	

	int partition(int * arr, int p, int q){

		int pivot = arr[q];

		int pIndex = p;

		for(int i = p ; i < q; i++){

			if(arr[i] <= pivot){
				swap(arr[i], arr[pIndex]);
				pIndex++;
			}
			
		}			                                                                           

		swap(arr[pIndex], arr[q]);

		return pIndex;

	}


	int random(int left, int right){

		srand(time(0));

		return (rand()%(right - left + 1) + left );

	}


	



	void solve(){

		int t;
		cin >> t;

		while(t--){

			int n;
			cin >> n;

			int * arr = new int[n];

			for(int i = 0 ; i < n ; i++)
				cin >> arr[i];

			//cout << partition(arr, 0, 4) << endl;

			int k;
			cin >> k;

			int left = 0 , right = n - 1;

			while(left <= right){

				int r = random(left, right);

				//cout << arr[r] << endl; 

				swap(arr[r], arr[right]);

					int pos = partition(arr, left, right);

				if(pos == k-1){
					cout << arr[pos] << endl;
					break;
				}
				else if(pos < k-1)
					left = pos + 1;
				else
					right = pos - 1;

			}

		}

	}



	int main(){
	    
	    ios_base::sync_with_stdio(false);
	    cin.tie(NULL);

	    solve();
	 
	    return 0;

	}
	        
 