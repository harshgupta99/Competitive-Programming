#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b;
ll BinarySearch(ll left, ll right){
	while(right >= left){
		ll mid = left + right/2;
		if((mid%a)%b != (mid%b)%a){
			answer = mid;
			right = mid-1;
		}
		else{
			left = mid + 1;
		}
	}
	return answer;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int q;
		cin >> a>> b>> q;
		while(q--){
			ll answer = 0;
			ll left, right;
			cin >> left >> right;
			answer = BinarySearch(left, right);
			cout<<answer<<"\n";

		}

	}
	return 0;
}