#include <bits/stdc++.h>
using namespace std;
int minDistance( string s, string t) {
        int n = s.length(); int m = t.length();

        vector<int>prev(m+1, 0) , dp(m+1 , 0);


         for (int j = 0; j <= m; j++) prev[j] = j;

         for (int i = 1; i <= n; i++) {
             dp[0] = i;
            for (int j = 1; j <= m; j++){
                if(s[i-1]== t[j-1]) dp[j] = prev[j-1];
                else{
                    int insert =   1 + dp[j-1];
                    int deletion = 1 + prev[j];
                    int replace =  1 + prev[j-1];

                    dp[j] =  min(insert , min(deletion , replace));
                }

            }
            prev = dp;

         }
         return prev[m];

    }
int main() {
	// your code goes here

	string s , t;
	cin>>s>>t;

	cout<<minDistance( s , t)<<endl;

	return 0 ;

}
