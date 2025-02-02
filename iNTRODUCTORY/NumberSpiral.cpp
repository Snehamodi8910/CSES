#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	// your code goes here

	int t ; cin>>t;
	while(t--){
    	    long long  Y , X;
    	    cin>>Y>>X;

    	    if (Y >= X) {
            // Compute the area of the inner square
                ll ans = (Y - 1) * (Y - 1);
                ll add = 0;

                // Check parity of Y to determine if numbers are in
                // increasing or decreasing order
                if (Y % 2 != 0) {
                    // Add X to the area if Yth row is odd
                    add = X;
                }
                else {
                    // Add 2*Y - X to the area if Yth row is even
                    add = 2 * Y - X;
                }
                // Print the final result
                cout << ans + add << "\n";
            }
        // If X is greater than or equal to Y, implying Xth
        // column is the outer boundary
        else {

            // Compute the area of the inner square
                ll ans = (X - 1) * (X - 1);
                ll add = 0;

                // Check parity of X to determine if numbers are in
                // increasing or decreasing order
                if (X % 2 == 0) {
                    // Add Y to the area if Xth column is even
                    add = Y;
                }
                else {
                    // Add 2*X - Y to the area if Xth column is odd
                    add = 2 * X - Y;
                }
            // Print the final result
            cout << ans + add << "\n";
        }
	}
    return 0 ;
}
