#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		// if(n > 2 && m!= 1 || m > 2 && n != 1){
		// 	cout<<"NO\n";
		// 	continue;
		// }
		if(n == 2 || m == 2){
			cout<<"YES\n";
			continue;
		}
		if(n == 1){
			cout<<"YES\n";
			continue;
		}
		if(m == 1){
			cout<<"YES\n";
			continue;
		}
		cout<<"NO\n";
	}
	return 0;
}