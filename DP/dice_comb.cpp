#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int main() {
	// your code goes here
    int n ; cin>>n ;
    vector<int>dp(1e6 +1 , 0);
    dp[0] = dp[1] = 1;
    for(int i = 2 ; i<=n ; i++){
        for(int j = 1 ; j<=6 && i-j>=0 ; j++){
            dp[i] = (dp[i] + dp[i-j])% MOD;
        }
    }
    cout<<dp[n]<<endl;

    return 0 ;
}
