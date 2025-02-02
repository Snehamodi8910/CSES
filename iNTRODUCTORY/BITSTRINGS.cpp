#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

// Function to compute (base^exp) % mod using modular exponentiation
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) { // If the current exponent bit is 1
            result = (result * base) % mod;
        }
        base = (base * base) % mod; // Square the base
        exp /= 2; // Move to the next bit
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    long long ans = mod_exp(2, n, mod);
    cout << ans << endl;

    return 0;
}
