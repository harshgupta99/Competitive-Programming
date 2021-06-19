#include<bits/stdc++.h>
using namespace std;
const int mxN = 2e5+10;
int n, k, z;
vector<int> arr(mxN);
long long int answer = 0;
void solve(){
    cin >> n >> k >> z;
    int dp[n+1];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i){
            dp[i] = dp[i-1] + arr[i];
        }
        else{
            dp[0] = arr[0];
        }
    }
    answer = 0;
    long long int pref = 0;
    for(int i = 0; i <= k; i++){
        if(i){
            long long int tmp = pref;
            tmp += arr[i];
            long long int tmp2 = arr[i] + arr[i-1];
            if(2*z <= k-i){
                int rem = k-i-2*z;
                tmp += tmp2*z;
                tmp += dp[i + rem] - dp[i];
            }
            else{
                int curr_moves = i;
                bool kaha = false;
                while(curr_moves < k){
                    if(!kaha){
                        tmp += arr[i-1];
                    }
                    else{
                        tmp += arr[i];
                    }
                    curr_moves++;
                    kaha ^= 1;
                }
            }
            answer = max(answer, tmp);
            pref += arr[i];
        }
        else{
            pref += arr[i];
        }
    }
    cout << answer << "\n";
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