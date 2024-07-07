#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    // dp[i][j] will store the number of ways to reach cell (i, j)
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Initialize dp[0][0]
    dp[0][0] = (grid[0][0] == '.') ? 1 : 0;

    // Fill the dp table
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '*') {
                dp[i][j] = 0; // trap, no ways to reach here
            } else {
                if (i > 0) {
                    dp[i][j] += dp[i-1][j]; // from above
                    dp[i][j] %= MOD;
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j-1]; // from left
                    dp[i][j] %= MOD;
                }
            }
        }
    }

    // Output the result for the bottom-right corner
    cout << dp[n-1][n-1] << endl;

    return 0;
}
