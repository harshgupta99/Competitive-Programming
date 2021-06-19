#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	scanf("%d", &n);
	// a*11 + b + 110*b + c + 1100*c
	if(n < 11){
		puts("NO");
		return;
	}
	if(n >= 1221){
		puts("YES");
		return;
	}
	for(int i = 0; 111*i <= n; i++){
		if((n - 111*i)%11 == 0){
			printf("YES\n");
			return;
		}
	}
	puts("NO");
	return;
}
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--) solve();
}