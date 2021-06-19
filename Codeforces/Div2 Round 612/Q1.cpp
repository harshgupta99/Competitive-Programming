#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int max_diff = INT_MIN/2;
		int curr_max_diff = 0;
		bool toggle = false;
		for(int i = 0; i < n; i++){
			if(s[i] == 'A' && !toggle){
				toggle = true;
			}
			else if(s[i] == 'A' && toggle){
				if(curr_max_diff > max_diff){
					max_diff = curr_max_diff;
				}
				curr_max_diff = 0;
			}
			else if(s[i] == 'P' && toggle){
				curr_max_diff++;
			}
		}
		if(curr_max_diff > max_diff){
			max_diff = curr_max_diff;
		}
		cout<<max_diff<<"\n";
	}
	return 0;
}