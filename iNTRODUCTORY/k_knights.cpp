#include <bits/stdc++.h>
using namespace std;

void twoKnights(int n) {
    for (int k = 1; k <= n; ++k) {
        // Total ways to place two knights
        long long total_ways = (1LL * k * k * (k * k - 1)) / 2;

        // Attacking pairs of knights
        long long attacking_pairs = 4 * (k * k - 3 * k + 2);

        // Valid placements
        long long valid_placements = total_ways - attacking_pairs;

        // Output the result for the current board size
        cout << valid_placements << endl;
    }
}

int main() {
    int n;
    cin >> n; // Input the size of the largest chessboard
    twoKnights(n);
    return 0;
}