#include <bits/stdc++.h>
using namespace std;

int distinct(int n , vector<int>& a){

    set<int>s(a.begin() , a.end());
    return s.size();


}

int main() {
	// your code goes here
	int n ; cin>>n ;
	vector<int>a(n);
	for(int i = 0 ; i<n ; i++) cin>>a[i];

    cout<<distinct(n , a)<<endl;

    return 0 ;


}
