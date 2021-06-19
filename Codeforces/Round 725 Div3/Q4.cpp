#include<bits/stdc++.h>
using namespace std;
int find_divisors(int n){
	int cnt = 0;
	for(int i = 2; i*i <= n; i++){
		while(n%i == 0){
			++cnt;
			n /= i;
		}
	}
	if(n > 1)
		++cnt;
	return cnt;
}
void solve(){
	// 36 48
	// 2*2*3*3 = 36 
	// 2*2*2*2*3 = 48
	int a, b, k;
	scanf("%d %d %d", &a, &b, &k);
	if(a > b)
		swap(a, b);
	int fact_a = find_divisors(a);
	int fact_b = find_divisors(b);
	int mn = (int)(fact_a > 0) + (int)(fact_b > 0);
	if(b%a == 0 && a != b)
		mn = min(mn, 1);
	int mx = fact_a + fact_b;
	if(k >= mn && k <= mx)
		puts("Yes");
	else
		puts("No");
	return;

}
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--) solve();
}

// 123 130
