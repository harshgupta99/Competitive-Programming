#include<bits/stdc++.h>
using namespace std;
vector<int> yoyo;
int BinarySearch(int left, int right, int ref){
	int ans = 0;
	while(right >= left){
		int mid = (left + right)/2;
		int val = (mid/2)*(4 + (mid - 1)*3);
		if(val > n){
			right = mid - 1;
		}
		else{
			ans = mid;
			if(((mid+1)*(4 + (mid)*3)) > n){
				return ans;
			}
			left = mid + 1;
		}
	}
	return ans;
}
void solve(){
	int temp = 2;
	int d = 3;
	int i = 0;
	while(temp > 10000000005){
		yoyo.push_back(temp);
		temp += (5 + (i*d));
		i++;
	}
	return;
}
int main(){
	int t;
	cin >> t;
	solve();
	while(t--){
		int n;
		cin >> n;
		vector<int>::iterator itr;
		int answer = 0;
		while(n > 1){
			answer++;
			itr = lower_bound(yoyo.begin(), yooy.end(), n);
			if(yoyo[itr- v.begin()] == n){
				break;
			}
			n = n - yoyo[itr - v.begin() - 1];
		}
		cout<<answer<<"\n";


	}
}