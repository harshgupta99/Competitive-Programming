#include<bits/stdc++.h>
using namespace std;
long long int changer(long long int a){
	vector<int> digits;
	long long int cpy = a + 1;
	while(a){
		digits.push_back(a%10);
		a /= 10;
	}
	reverse(digits.begin(), digits.end());
	vector<int> digits_now;
	while(cpy){
		digits_now.push_back(cpy%10);
		cpy /= 10;
	}
	reverse(digits_now.begin(), digits_now.end());
	long long int cnt = 0LL;
	while(!digits.empty()){
		cnt += 1LL*(digits.back() != digits_now.back());
		digits.pop_back();
		digits_now.pop_back();
	}
	cnt += 1LL * digits_now.size();
	return cnt;
}
void solve(){
	long long int a, b;
	scanf("%lld %lld", &a, &b);
	long long int answer = 0LL;
	while(a != b){
		answer += changer(a++);
	}
	printf("%lld\n", answer);
	return;
}
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--) solve();
}