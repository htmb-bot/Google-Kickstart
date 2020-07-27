#include "bits/stdc++.h"
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ios::sync_with_stdio(false),cin.tie(0);

	int tab[1001][1001];
	
	int N,t; cin >> N;
	t = N;

	while(t--)
	{

		int n,q; cin >> n >> q;
		int d[n-1];

		for(int i=0;i<n-1;i++){
			cin >> d[i];
		}

		for(int s = 0;s<n;s++){
			tab[s][0] = s;
			int top,bottom;
			top = s;
			bottom = s-1;
			for(int i=1;i<n;i++){
				cout << bottom << " " << top << endl;
				int mini=1000000;
				bool droite;
				if(top<n-1){
					mini = d[top];
					droite = true;
				}
				if(bottom>=0){
					mini = min(d[bottom],mini);
					if(mini == d[bottom]) droite = false;
				}
				if(droite){
					tab[s][i] = top+1;
					top++;
				}
				else{
					tab[s][i] = bottom;
					bottom--;					
				}

			}
		}

		cout << "Case #" << N-t << ": ";

		for(int i=0;i<q;i++){
			int f,g;
			cin >> f >> g;
			cout << tab[f-1][g-1]+1 << " ";
		}

		cout << endl;

	}
	return 0;
}