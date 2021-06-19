#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    if(k == 1){
        string ans = "";
        for(int i = 0; i < n; i++){
            ans += 'a';
        }
        cout << ans << "\n";
        return;
    }
    string answer = "";
    // abacadbcbdcd
    int index = 0; 
    while(index < n){
        for(int i = 0; i < k; i++){
            for(int j = i+1; j < k; j++){
                answer += ('a' + i);
                index++;
                if(index == n){
                    break;
                }
                answer += ('a' + j);
                index++;
                if(index == n){
                    break;
                }
            }
            if(index == n){
                break;
            }
        }
    }
    cout << answer << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}