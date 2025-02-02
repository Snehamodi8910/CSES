/* #include <bits/stdc++.h>
using namespace std;

bool f(int l, int r, vector<vector<int>>& dp) {
    if (l == 0 && r == 0) return true;
    if (l < 0 || r < 0) return false;

    if (dp[l][r] != -1) return dp[l][r];

    return dp[l][r] = f(l - 1, r - 2, dp) || f(l - 2, r - 1, dp);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));

        if (f(a, b, dp)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
 */

//the above code gives TLE after memoization too
// we need to use maths
//we can see a pattern that (1, 2) and(2 ,1 ) if the sum of two numbers is divisible by 3
//and twice the minum value > max value

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        if ((a + b) % 3 == 0 && 2 * min(a, b) >= max(a, b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}


