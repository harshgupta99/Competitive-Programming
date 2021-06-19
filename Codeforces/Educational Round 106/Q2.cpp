#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin >> s;
    int n = (int)s.size();
    // after getting 2 consecutve ones no zero should be there
    // after getting 2 consecutive zeros, rest should be sorted
    bool consec_ones = false;
    bool consec_zeros = false;
    vector<bool> keep(n, true);
    bool last_removed = false;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            if(consec_ones){
                if(!last_removed){
                    last_removed = true;
                    keep[i] = false;
                }
            }
            else{
                last_removed = false;
            }
            
        }
        else{
            if(!last_removed && !consec_ones){
                last_removed = true;
                keep[i] = false;
            }
            else{
                consec_ones = true;
                last_removed = false;
            }
        }
    }
    string to_check = "";
    for(int i = 0; i < n; i++){
        if(keep[i]){
            to_check += s[i];
        }
    }
    if(is_sorted(to_check.begin(), to_check.end())){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1]){
            if(s[i] == '1'){
                consec_ones = true;
            }
            else{
                if(consec_ones){
                    cout << "NO\n";
                    return;
                }
                consec_zeros = true;
                to_check = s.substr(i+1);
                break;
            }
        }
    }
    if(consec_zeros){
        if(is_sorted(to_check.begin(), to_check.end())){
            cout << "YES\n";
            return;
        }
        else{
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}