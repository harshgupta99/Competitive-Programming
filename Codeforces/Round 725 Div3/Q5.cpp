#include<bits/stdc++.h>
using namespace std;
void solve(){
	long long int a, b;
	scanf("%lld %lld", &a, &b);
	long long int answer = 0LL;
	long long int base = 1LL;
	for(int len = 0; len <= 9; len++){
	    answer += (b/base) - (a/base);
	    base *= 10LL;
	}
	printf("%lld\n", answer);
	return;
}
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--) solve();
}