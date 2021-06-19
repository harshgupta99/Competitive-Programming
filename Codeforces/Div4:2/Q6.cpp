//https://codeforces.com/gym/102942/problem/F
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> cnt(1e6+10, 0);
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int left = 0;
    int answer = 0;
    int curr = 0;
    for(int i = 0; i < n; i++){
        if(cnt[a[i]]){
            ++cnt[a[i]];
            curr++;
        }
        else if(a[i] <= k){
            k -= a[i];
            cnt[a[i]]++;
            curr++;
        }
        else{
            answer = max(answer, curr);
            while(left < i && a[i] > k){
                curr--;
                cnt[a[left]]--;
                if(cnt[a[left]] == 0){
                    k += a[left];
                }
                left++;
            }
            if(k >= a[i]){
                k -= a[i];
                curr++;
                cnt[a[i]]++;
            }
            else{
                left = i+1;
                curr = 0;
            }
        }
    }
    answer = max(answer, curr);
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