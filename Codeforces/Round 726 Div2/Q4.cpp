#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string answer = "";
	string curr = "";
	for(int i = 0; i < n; i++){
		curr += s[i];
		string X = curr;
		while((int)curr.size() < k)
			curr += curr;
		curr.resize(k);
		if(answer.empty() || answer > curr)
			answer = curr;
		curr = X;
	}
	cout << answer << "\n";
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_cases = 1;
	while(test_cases--) solve();
}