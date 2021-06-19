#include<bits/stdc++.h>
using namespace std;
string a;
void solve(){
	int n, m;
	scanf("%d %d", &n, &m);
	cin >> a;
	while(m--){
		bool zero = false, one = false;
		for(int i = 0; i < n; i++){
			zero |= (a[i] == '0');
			one |= (a[i] == '1');
		}
		if(!zero || !one)
			break;
		string b = a;
		for(int i = 0; i < n; i++){
			if(a[i] == '0'){
				int cnt = 0;
				if(i-1 >= 0 && a[i-1] == '1')
					++cnt;
				if(i+1 < n && a[i+1] == '1')
					++cnt;
				if(cnt == 1)
					b[i] = '1';
			}
		}
		a = b;
	}
	cout << a << "\n";
	return;
}
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--) solve();
}