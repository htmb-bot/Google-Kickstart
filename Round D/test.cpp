#include "bits/stdc++.h"
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ios::sync_with_stdio(false),cin.tie(0);
	int n = 10000;
	long long y = 0;
	for(int i=0;i<n;i++){
		y += 12345678987654321;
	} 

	cout << "test " << fixed << setprecision(7) << y/(long double)n*n << endl;

	return 0;
}