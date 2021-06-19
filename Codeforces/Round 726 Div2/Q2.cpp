#include<bits/stdc++.h>
using namespace std;
long long int n, m, x, y;
long long int helper(pair<long long int, long long int> &a, pair<long long int, long long int> &b){
	long long int one_way = abs(x - a.first) + abs(y - a.second);
	one_way += abs(a.first - b.first) + abs(a.second - b.second);
	one_way += abs(x - b.first) + abs(y - b.second);
	long long int two_way = abs(x - b.first) + abs(y - b.second);
	two_way += abs(b.first - a.first) + abs(b.second - a.second);
	two_way += abs(a.first - x) + abs(a.second - y);
	return max(one_way, two_way);
}
void solve(){
	cin >> n >> m >> x >> y;
	vector<pair<long long int, long long int> > possible;
	possible.push_back({1LL, 1LL});
	possible.push_back({1LL, m});
	possible.push_back({n, 1LL});
	possible.push_back({n, m});
	long long int best_dist = -1e8;
	pair<int, int> best_answer;
	for(int i = 0; i < 4; ++i){
		for(int j = i; j < 4; j++){
			long long int ans = helper(possible[i], possible[j]);
			if(ans > best_dist){
				best_dist = ans;
				best_answer = {i, j};
			}
		}
	}
	cout << possible[best_answer.first].first << " " << possible[best_answer.first].second << " " << possible[best_answer.second].first << " " << possible[best_answer.second].second << "\n";
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