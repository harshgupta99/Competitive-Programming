#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> mp;
    int maxy = 0;
    for(int i = 0; i < n; i++){
        mp[s[i]]++;
        maxy = max(maxy, mp[s[i]]);
    }
    int answer = n - maxy;
    // cout << answer << "\n";
    for(char i = '0'; i <= '9'; i++){
        for(char j = '0'; j <= '9'; j++){
            if(i == j){
                continue;
            }
            int curr = 0;
            // try for i j pair
            bool find = false;
            int len = 0;
            for(int k = 0 ; k < n; k++){
                if(!find){
                    if(s[k] == i){
                        find = true;
                        len++;
                    }
                    else{
                        curr++;
                    }
                }
                else{
                    if(s[k] == j){
                        find = false;
                    }
                    else{
                        curr++;
                        len++;
                    }
                }
            }
            if(len%2){
                curr++;
            }
            answer = min(answer, curr);
        }
    }
    cout << answer << "\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}