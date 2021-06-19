#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	int mn_index , mx_index, mn = 1e9, mx = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if(a[i] < mn){
			mn = a[i];
			mn_index = i;
		}
		if(a[i] > mx){
			mx = a[i];
			mx_index = i;
		}
	}
	int ans = max(mn_index, mx_index) + 1;
	ans = min(ans, n - min(mn_index, mx_index));
	ans = min(ans, 1 + min(mn_index, mx_index) + n - max(mn_index, mx_index));
	printf("%d\n", ans);
	return;


}
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--) solve();
}