#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	int l = log2(n);
	cout << (1 << l) - 1 << "\n";
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}