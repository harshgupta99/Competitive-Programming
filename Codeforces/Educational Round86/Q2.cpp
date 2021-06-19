#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >>t;
	while(t--){
		string s;
		cin >>s;
		string answer;
		queue<char> q;
		set<char> st;
		for(int i = 0; i < s.size();i++){
			q.push(s[i]);
			st.push(s[i]);
		}
		if(st.size() == 1){
			// We can make a string with one period
			cout<<s<<"\n";
			continue;
		}
		for(int i = 0; i < 2*s.size(); i++){
			if(q.empty()){
				break;
			}
			if(i == 0){
				answer += q.front();
				q.pop();
				continue;
			}
			if(answer[i-1] == q.front()){
				if(q.front() == '1'){
					answer += '0';
				}
				else{
					answer += '1';
				}
				continue;
			}
		}
		cout<<answer<<"\n";
	}
	return 0;
}