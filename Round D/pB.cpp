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

		int ans=0;
		int n; cin >> n;
		int tab[n];
		int ans1 = 0;
		int val1 = 0;
		int ans2 = 0;
		int val2 = 0;

		for(int i=0;i<n;i++){
			cin >> tab[i];
		}

		vector<int> series;
		series.push_back(1);
		bool plus = true;
		bool minus = true;
		for(int i=1;i<n;i++){
			if(tab[i]>tab[i-1]&&plus){
				series[(int) series.size()-1]++;
				minus = false;
			}
			else if(tab[i]>tab[i-1]&&!plus){
				series.push_back(2);
				plus = true;
				minus = false;
			}
			else if(tab[i]<tab[i-1]&&plus){
				series.push_back(2);
				plus = false;
				minus = true;				
			}
			else if(tab[i]<tab[i-1]&& minus){
				series[(int) series.size()-1]++;
				plus = false;				
			}
		}

		for(int i=0;i<(int) series.size();i++){
			ans+=(series[i]-1)/4;
		}

		cout << "Case #" << N-t << ": " << ans << endl;
	}
	return 0;
}