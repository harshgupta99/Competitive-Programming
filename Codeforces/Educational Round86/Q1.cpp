#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin >>t;
	while(t--){
		ll x, y;
		cin >> x >>y;
		ll a, b;
		cin >>a >>b;
		// First we aim to make abs(x) == abs(y)
		// Perform b only if b < 2*a
		bool flag = false;
		int type;
		if(b < 2*a){
			// This means that we use b to perform 2a operations at once
			flag = true;
		}
		// We can use b only if the polarity of both x and y is same in type 0 or type 2
		if(x > 0 && y > 0){
			type = 0;
		}
		else if(x > 0 && y < 0){
			type = 1;
		}
		else if(x < 0 && y < 0){
			type = 2;
		}
		else if(x < 0 && y > 0){
			type = 3;
		}
		ll amount = 0;
		if(type == 0){
			amount += (abs(x-y)*a);
			if(flag){
				amount += (min(x, y)*b);
			}
			else{
				amount += (2*a*(min(x, y)));
			}
		}
		else if(type == 1){
			// B cannot be used
			// x ghatao and y badhao
			amount += a*(x + abs(y));
		}
		else if(type == 2){
			amount += (abs(abs(x) - abs(y)))*a;
			if(flag){
				amount += (min(abs(x), abs(y))*b);
			}
			else{
				amount += (2*a*(min(abs(x), abs(y))));
			}
		}
		else if(type == 3){
			amount += a*(abs(x) + y);
		}
		cout<<amount<<"\n";

	}
	return 0;
}