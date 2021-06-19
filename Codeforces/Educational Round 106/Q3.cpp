#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long int answer = 1e18;
    long long int group1 = 0LL;
    long long int group2 = 0LL;
    answer = n*a[0] + n*a[1];
    long long int min_group1 = a[0];
    long long int min_group2 = a[1];
    long long int cnt_group1 = 0LL;
    long long int cnt_group2 = 0LL;
    for(int i = 2; i < n; i++){
        if(i&1){
            // add in group2
            cnt_group2++;
            if(a[i] < min_group2){
                group2 += min_group2;
                min_group2 = a[i];
            }
            else{
                group2 += a[i];
            }
            if(i == 2){
                long long int score = n*a[1] + (n-1)*min_group2 + group2;
                answer = min(answer, score);
            }
            else{
                long long int score = (n-cnt_group2)*min_group2 + group2 + group1 + (n - cnt_group1)*min_group1;
                answer = min(answer, score);

            }
            
        }
        else{
            // add in group1
            ++cnt_group1;
            if(a[i] < min_group1){
                group1 += min_group1;
                min_group1 = a[i];
            }
            else{
                group1 += a[i];
            }
            long long int score = (n-cnt_group2)*min_group2 + group2 + group1 + (n - cnt_group1)*min_group1;
            answer = min(answer, score);
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