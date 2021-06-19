#include<bits/stdc++.h>
using namespace std;
void print1(int i, int j){
	printf("1 %d %d\n", i, j);
}
void print2(int i, int j){
	printf("2 %d %d\n", i, j);
}
void solve(){
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d\n", 6*n/2);
	for(int i = 1 ; i <= n; i += 2){
		print1(i, i+1);
		print2(i, i+1);
		print1(i, i+1);
		print1(i, i+1);
		print2(i, i+1);
		print1(i, i+1);
	}
	return;
}
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--) solve();
}