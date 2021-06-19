#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	vector<int> cnt(101, 0);
	int mx = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	for(int i = 1; i <= 100; i++){
		if(cnt[i] != 0){
			printf("%d\n", n - cnt[i]);
			return;
		}
	}
	
	return;
}
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--) solve();
}
// 9 1 9 9 
// 
