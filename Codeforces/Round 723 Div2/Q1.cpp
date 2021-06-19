#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	scanf("%d", &n);
	n *= 2;
	vector<pair<int, int> > a(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < n/2; i++){
		printf("%d %d ", a[i].first, a[n/2+i].first);
	}
	puts("");
	return;
}
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--) solve();
}