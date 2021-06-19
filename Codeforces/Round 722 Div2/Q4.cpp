#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main(){
	int n;
	scanf("%d", &n);	
	auto add = [&](long long int &a, long long int b) -> void{
		a = (a + b) % mod;
		if(a < 0LL)
			a += mod;
		return;
	};
	vector<long long int> dp(n+1, 0LL);
	for(int i = 1; i <= n; i++)
		for(int j = 2*i; j <= n; j += i)
			dp[j]++;

	long long int sum = 1LL;
	dp[0] = 1LL;
	for(int i = 1; i <= n; i++){
		add(dp[i], sum);
		add(sum, dp[i]);
	}
	printf("%lld\n", dp[n]);
	return 0;
}