#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n ; cin>>n ; long long  sum = 0 ;
	for(int k = 1 ; n >= pow(5 , k); k++){

	        sum += n / pow(5 , k);

	}
	cout<<sum<<endl;
	return 0 ;

}
