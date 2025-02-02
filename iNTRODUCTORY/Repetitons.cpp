#include <bits/stdc++.h>
using namespace std;

int f(string s){
    int n = s.length();
    int cnt = 1 ; int maxi = 1;

    for(int i = 0 ; i<n-1 ; i++){
        if(s[i] == s[i+1]) {
            cnt++;
            maxi = max(maxi , cnt);
        }
        else {
            cnt = 1;
        }
    }
    return maxi ;
}

int main() {
	// your code goes here

	string s; cin>>s;

	cout<<f(s)<<endl;
	return 0 ;


}
