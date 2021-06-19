#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<vector<int> > edges(N);
vector<pair<long long int, long long int> > a(N);
pair<long long int, long long int> dfs(int node, int par, long long int val = 0LL){
	pair<long long int, long long int> ans = {0LL, 0LL};
	if(par != 0){
		ans.first = abs(a[node].first - val);
		ans.second = abs(a[node].second - val);
	}
	for(auto child : edges[node]){
		if(child != par){
			pair<long long int, long long int> a1 = dfs(child, node, a[node].first);
			ans.first += max(a1.first, a1.second);
			a1.first -= abs(a[node].first - a[child].first);
			a1.first += abs(a[node].second - a[child].first);
			a1.second -= abs(a[node].first - a[child].second);
			a1.second += abs(a[node].second - a[child].second);
			ans.second += max(a1.first, a1.second);
		}
	}
	return ans;
}
void solve(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		edges[i].clear();
	for(int i = 1; i <= n; i++)
		scanf("%lld%lld", &a[i].first, &a[i].second);
	for(int i = 0; i < n-1; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	pair<long long int, long long int> ans = dfs(1, 0);
	long long int answer = max(ans.first, ans.second);
	printf("%lld\n", answer);
	return;
}
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--) solve();
}