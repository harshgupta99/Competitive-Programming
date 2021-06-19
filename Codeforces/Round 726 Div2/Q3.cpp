#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, pair<int, int> > mp;
	int start = -1;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	for(int i = 0; i < n-1; i++){
		if(mp.find(a[i+1] - a[i]) == mp.end()){
			mp[a[i+1] - a[i]] = {i, i+1};
		}
	}
	vector<bool> taken(n, false);
	taken[mp.begin()->second.first] = true;
	taken[mp.begin()->second.second] = true;
	vector<int> answer(n);
	answer[0] = a[mp.begin()->second.first];
	answer[n-1] = a[mp.begin()->second.second];
	int idx = 1;
	for(int i = mp.begin()->second.first+1; i < n; i++){
		if(!taken[i]){
			answer[idx++] = a[i];
		}
	}
	for(int i = 0; i < mp.begin()->second.first; i++){
		if(!taken[i]){
			answer[idx++] = a[i];
		}
	}
	for(auto x : answer)
		cout << x << " ";
	cout << "\n";
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_cases;
	cin >> test_cases;
	while(test_cases--) solve();
}