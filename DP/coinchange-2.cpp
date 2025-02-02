#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int change(int amt, vector<int>& c) {
    int n = c.size();
    vector<long long> dp(amt + 1, 0);
    dp[0] = 1;  // Base case: One way to make amount 0

    // Iterate over coins
    for (int ind = 0; ind < n; ind++) {
        for (int t = c[ind]; t <= amt; t++) {
            dp[t] = (dp[t] + dp[t - c[ind]]) % mod;
        }
    }

    return dp[amt] % mod;
}

int main() {
    int n, amt;
    cin >> n >> amt;
    vector<int> c(n);  // Correct size
    for (int i = 0; i < n; i++) cin >> c[i];

    cout << change(amt, c) << endl;
    return 0;
}
