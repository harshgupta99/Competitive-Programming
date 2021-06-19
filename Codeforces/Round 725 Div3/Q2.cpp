#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	int sum = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	if(sum%n){
		puts("-1");
		return;
	}
	sum /= n;
	int cnt = 0;
	for(auto x : a)
		cnt += (x > sum);
	printf("%d\n", cnt);
	return;
}
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--) solve();
}