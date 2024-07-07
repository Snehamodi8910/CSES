#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000;
const int maxX = 1e5;

int N, X, price[maxN], pages[maxN], dp[maxX + 1];

int solve(int N, int X, vector<int>& price, vector<int>& pages) {
    fill(dp + 1, dp + X + 1, -1);
    for (int i = 0; i < N; i++) {
        for (int j = X - price[i]; j >= 0; j--) {
            if (dp[j] != -1) {
                dp[j + price[i]] = max(dp[j + price[i]], dp[j] + pages[i]);
            }
        }
    }
    for (int i = 1; i <= X; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
    }
    return dp[X];
}

int main() {
    cin >> N >> X;
    vector<int> price(N), pages(N);
    for (int i = 0; i < N; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> pages[i];
    }

    cout << solve(N, X, price, pages) << endl;
    return 0;
}
