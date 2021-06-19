#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, deque<int> > mp;
	map<int, int> lst;
	long long int answer = 0;
	vector<bool> mark(n+10, false);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		//answer += answer;
		if(lst.find(a[i]) == lst.end()){
			lst[a[i]] = i;
		}
		else{
			mp[a[i]].push_back(n - i);
			assert(lst[a[i]] >= 0 && lst[a[i]] < n);
			mark[lst[a[i]]] = true;
			lst[a[i]] = i;
		}
	}
	for(auto &x : mp){
		for(int i = x.second.size()-2; i >= 0; i--){
			x.second[i] += x.second[i+1];
		}
	}
	long long int cnt = 0;
	for(int i = 0; i < n; i++){
		if(!mark[i]){
			++cnt;
			continue;
		}
		if(mp[a[i]].empty()){
			continue;
		}
		answer += 1LL * (cnt + 1) * mp[a[i]].front() * 1LL;
		mp[a[i]].pop_front();
		cnt++;
	}
	cout << answer << "\n";
	return;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}