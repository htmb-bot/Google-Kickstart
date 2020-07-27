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
		int a,b; cin >> a >> b;
		long long cola[n];
		long long colb[n];
		int points[n];
		bool checka[n];
		for(int i=0;i<n;i++){
			checka[i] = false;
			cola[i] =0;
			colb[i] = 0;
			points[i] = 0;
		}

		int tree[n];

		tree[0] = -1;
		
		for(int i=0;i<n-1;i++){
			int u; cin >> u;
			tree[i+1] = u-1;
			points[u-1]++;
		}
		
		vector<int> feuilles;


		for(int i=0;i<n;i++){
			if(points[i] == 0) feuilles.push_back(i);
		}


		for(int i=0;i<(int) feuilles.size();i++){
			int label = feuilles[i];
//			cout <<"feuille " << i+1 << " : " << 1+feuilles[i] << endl;
			vector<int> branch;
			branch.push_back(label);
			while(tree[label] != -1){
				branch.push_back(tree[label]);
				label = tree[label];
			}
			bool checked = false;
			int petitd;
			int less = 0;
			for(int j=0;j<(int) branch.size();j++){
				if(checka[branch[j]] && !checked){
					checked = true;
					petitd = (int) branch.size() - j;
				}
				cola[branch[j]] += (j/a);
				colb[branch[j]] += (j/b);
				cola[branch[j]] -= (less/a);
				colb[branch[j]] -= (less/b);
				checka[branch[j]] = true;
				if(checked){
					less++;
				}
			}
		}

		for(int i=0;i<n;i++){
			cola[i] += 1;
			colb[i] += 1;
		}
/*
		for(int i=0;i<n;i++){
			cout <<  cola[i] << " ";
		}
		cout << endl;
		for(int i=0;i<n;i++){
			cout <<  colb[i] << " ";
		}		
		cout << endl;
*/

		long long ans = 0;
		for(int i = 0;i<n;i++){
			long long temp = 0;
			temp += (n)*cola[i];
			temp+= (n)*colb[i];
			temp-= cola[i]*colb[i];
			ans += temp;
		}


		cout << "Case #" << N-t << ": " << fixed << setprecision(7) << (double) ans / (double) (n*n) << endl;
	}

	return 0;
}