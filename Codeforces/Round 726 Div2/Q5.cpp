#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	if(n&1)
		cout << "Bob\n";
	else{
		int cnt = 0;
		while(n%2 == 0){
			++cnt;
			n /= 2;
		}
		if(n > 1)
			cout << "Alice\n";
		else if(cnt % 2 == 1)
			cout << "Bob\n";
		else
			cout << "Alice\n";
	}
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