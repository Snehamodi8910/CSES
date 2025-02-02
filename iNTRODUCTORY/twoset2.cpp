#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Sum of first n natural numbers
    long long total_sum = (n * (n + 1)) / 2;

    // If the total sum is odd, division into two sets with equal sum is not possible
    if (total_sum % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }

    // Otherwise, we need to partition the set
    cout << "YES" << endl;

    // The sum we want for each subset is total_sum / 2
    long long target_sum = total_sum / 2;

    // First set and second set
    vector<int> set1, set2;

    // Start from n and try to fill the first set
    for (int i = n; i >= 1; i--) {
        if (target_sum >= i) {
            set1.push_back(i);
            target_sum -= i;
        } else {
            set2.push_back(i);
        }
    }

    // Output the first set
    cout << set1.size() << endl;
    for (int num : set1) {
        cout << num << " ";
    }
    cout << endl;

    // Output the second set
    cout << set2.size() << endl;
    for (int num : set2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
