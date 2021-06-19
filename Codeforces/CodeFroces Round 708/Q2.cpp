#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;
    vector<long long int> a(n);
    vector<int> cnt(m, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[(a[i]%m)]++;
    }
    int answer = 0;
    if(cnt[0]){
        ++answer;
    }
    for(int i = 1; i <= m/2; i++){
        if(cnt[i] == 0 && cnt[m-i] == 0){
            continue;
        }
        if(i + i == m){
            ++answer;
        }
        else{
            // try matching i and m - i 
            if(cnt[i] > cnt[m-i]){
                answer++;
                cnt[i] -= cnt[m-i];
                cnt[i]--;
                cnt[m-i] = 0;
                answer += cnt[i];
                cnt[i] = 0;
            }
            else if(cnt[i] == cnt[m-i]){
                ++answer;
            }
            else{
                ++answer;
                cnt[m-i] -= cnt[i];
                cnt[m-i]--;
                cnt[i] = 0;
                answer += cnt[m-i];
                cnt[m-i] = 0;
            }
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
// 8 1,7,1 1 4,4 6,2 5