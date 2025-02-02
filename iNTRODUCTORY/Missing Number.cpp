#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<int>& a) {
    unordered_map<int, int> mp;
    for(int i : a) mp[i]++;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(mp.find(i) == mp.end()) {
            ans = i;
            break;  // Once we find the missing number, we can break
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    // Initialize vector with size n
    vector<int> a(n);

    // Input starts from index 0 to n-1
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << f(n, a) << endl;
    return 0;
}