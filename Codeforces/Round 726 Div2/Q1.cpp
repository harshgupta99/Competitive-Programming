#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	if(sum == n){
		cout << "0\n";
		return;
	}
	else if(sum > n){
		cout << sum - n << "\n";
		return;
	}
	cout << "1\n";
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