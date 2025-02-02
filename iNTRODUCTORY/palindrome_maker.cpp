#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;

    int n = s.length();
    if(n == 1) {
        cout << s << endl;
        return 0;
    }

    if(n == 2) {
        if(s[0] != s[1]) cout << "NO SOLUTION" << endl;
        else cout << s << endl;
        return 0;
    }

    vector<int> f(26, 0);  // To store frequencies of characters
    for(int i = 0; i < n; i++) {
        f[s[i] - 'A']++;
    }

    int odd = 0;
    char odd_char = 0;  // To store the character with odd frequency
    for(int i = 0; i < 26; i++) {
        if(f[i] % 2 != 0) {
            odd++;
            odd_char = i + 'A';  // Storing the character with odd frequency
        }
    }

    if(odd > 1){
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    string first_half = "", second_half = "";

    // Construct the first half and second half
    for(int i = 0; i < 26; i++) {
        if(f[i] % 2 == 0) {
            first_half += string(f[i] / 2, i + 'A');
        }
    }

    // Place the odd character in the middle (if exists)
    string middle = (odd == 1) ? string(f[odd_char - 'A'], odd_char) : "";

    // The second half is just the reverse of the first half
    second_half = first_half;
    reverse(second_half.begin(), second_half.end());

    // Combine everything into a palindrome
    cout << first_half + middle + second_half << endl;

    return 0;
}
