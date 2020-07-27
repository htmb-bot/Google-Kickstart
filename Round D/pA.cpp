#include "bits/stdc++.h"
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ios::sync_with_stdio(false),cin.tie(0);
	
	int N,t; cin >> N;
	t = N;

	while(t--)
	{
		int n; cin >> n;
		int tab[n];
		for(int i=0;i<n;i++) cin >> tab[i];
		int maxi = -1;	
		int ans = 0;

		for(int i=0;i<n-1;i++){
			if(tab[i]>maxi){
				maxi = tab[i];
				if(tab[i]>tab[i+1]) ans++;
			}
		}

		if(tab[n-1]>maxi) ans++;

		cout << "Case #" << N-t << ": " << ans << endl;
	}
	return 0;
}