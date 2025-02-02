#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxN = 100;
const int maxX = 1e6;
const ll MOD = 1e9+7;
//remember in this question its no mentioned that we have to follow the order so our first priority will be target to be over first the loop for target than for index if(dp[i] != 0)
int main() {
    int N, X;
    cin >> N >> X;

    vector<int> c(N);
    for(int i = 0; i < N; i++)
        cin >> c[i];

    vector<ll> dp(X + 1, 0);
    dp[0] = 1;

    for(int i = 0; i < X; i++) {
        if(dp[i] != 0) {
            for(int j = 0; j < N; j++) {
                if(i + c[j] <= X) {
                    dp[i + c[j]] = (dp[i + c[j]] + dp[i]) % MOD;
                }
            }
        }
    }

    cout << dp[X] << endl;
    return 0;
}
