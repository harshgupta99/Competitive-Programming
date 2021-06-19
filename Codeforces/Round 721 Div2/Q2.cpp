#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	if(n == 1){
		cout << "BOB\n";
		return;
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '0'){
			++cnt;
		}
	}
	if(n&1 && s[n/2] == '0'){
		// special case 
		cnt--;
		if(cnt == 0){
			cout << "BOB\n";
			return;
		}
		if(cnt%2 == 0){
			cout << "ALICE\n";
		}
		else{
			cout << "DRAW\n";
		}
		return;
	}
	cout << "BOB\n";
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