#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7 ;

int coinChange(vector<int>& c, int amt) {
        int n = c.size();
        vector<vector<int>> dp(n, vector<int>(amt + 1, INT_MAX));

        // Initialize base cases
        for (int j = 0; j <= amt; ++j) {
            if (j % c[0] == 0) dp[0][j] = j / c[0];
        }

        // Fill the dp array
        for (int ind = 1; ind < n; ++ind) {
            for (int target = 0; target <= amt; ++target) {
                int exclude = dp[ind-1][target];
                int include = INT_MAX;
                if (target >= c[ind]) {
                    if (dp[ind][target - c[ind]] != INT_MAX) {
                        include = 1 + dp[ind][target - c[ind]];
                    }
                }
                dp[ind][target] = min(include, exclude) ;
            }
        }

        int result = dp[n-1][amt];
        return result == INT_MAX ? -1 : result;
}
int main() {
	// your code goes here
	int n , x;
	cin>>n>>x;
	vector<int>c(n);
	for(int i =  0 ; i<n ; i++) cin>>c[i];

	cout<<coinChange(c , x )<<endl;
	return 0 ;



}
