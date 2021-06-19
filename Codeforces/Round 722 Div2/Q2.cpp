#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int ans = 0;
	// we can take atmost one positive integer
	vector<int> selected;
	for(int i = 0; i < n; i++){
		if(a[i] <= 0){
			++ans;
			selected.push_back(a[i]);
		}
	}
	sort(selected.begin(), selected.end());
	int mn = 1e9;
	for(int i = 1; i < (int)selected.size(); i++)
		mn = min(mn, abs(abs(selected[i]) - abs(selected[i-1])));
	//cerr << mn << "\n";
	for(int i = 0; i < n; i++){
		if(a[i] <= mn && a[i] > 0){
			++ans;
			break;
		}
	}
	printf("%d\n", ans);
	// try to take atmost one positive
	// if k is the positive number
	// range is +k and -k

}
// -3 -2 2 
// 10 1 -3 -5 
// -3 -5 1 10 
// -3 -2 -1 1 1 1 1 
// 1 1 2 0 0 0 0
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--) solve();
}