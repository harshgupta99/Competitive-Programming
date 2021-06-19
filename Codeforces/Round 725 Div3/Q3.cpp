#include<bits/stdc++.h>
using namespace std;
void solve(){
	// a[i] + a[j] >= l
	// a[i] + a[j] <= r
	// a[i] >= l - a[j]
	// a[i] <= r - a[j]
	int n;
	scanf("%d", &n);
	int l, r;
	scanf("%d %d", &l, &r);
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	long long int answer = 0LL;
	auto it = a.begin();
	sort(a.begin(), a.end());
	// 1 2 5
	// 
	for(int i = 0; i < n; i++){
		it++;
		auto low = lower_bound(it, a.end(), l - a[i]) - a.begin();
		auto high = lower_bound(it, a.end(), r + 1 - a[i]) - a.begin();
		answer += 1LL * (high - low);
	}
	printf("%lld\n", answer);
	return;
}
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--) solve();
}