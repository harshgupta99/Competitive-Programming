#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<string> v;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		v.push_back(s);
	}
	int answer = 0;
	for(int i = 0; i < n-2 ; i++){
		string curr1 = v[i];
		for(int j = i+1 ; j < n-1; j++){
			string curr2 = v[j];
			for(int z = j + 1; z < n; z++){
				string curr3 = v[z];
				bool flag = true;
				for(int l = 0; l < k;l++){
					if(curr1[l] == curr2[l]){
						if(curr3[l] == curr1[l]){
							continue;
						}
						else{
							flag = false;
							break;
						}
					}
					else{
						if(curr3[l] != curr1[l] && curr3[l] != curr2[l]){
							continue;
						}
						else{
							flag = false;
							break;
						}
					}
				}
				if(flag){
					answer++;
					// cout<<curr1<<" "<<curr2<<" "<<curr3<<"\n";
				}
			}
		}
	}
	cout<<answer<<"\n";
	return 0;
}