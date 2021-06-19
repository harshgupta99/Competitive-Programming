//https://codeforces.com/contest/1475/problem/D
#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n, m;
    cin >> n >> m;
    vector<long long int> a(n);
    long long int sum = 0LL;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    vector<long long int> one, two;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x == 1){
            one.push_back(a[i]);
        }
        else{
            two.push_back(a[i]);
        }
    }
    if(sum < m){
        cout << "-1\n";
        return;
    }
    int answer = 0;
    long long int free = 0LL;
    sort(one.begin(), one.end());
    sort(two.begin(), two.end());
    if(one.empty()){
        while(free < m && !two.empty()){
            answer += 2;
            free += two.back();
            two.pop_back();
        }
        cout << answer << "\n";
        return;
    }
    if(two.empty()){
        while(free < m && !one.empty()){
            answer += 1;
            free += one.back();
            one.pop_back();
        }
        cout << answer << "\n";
        return;
    }
    // 2 2
    // 1 3
    while(free < m && !one.empty() && !two.empty() && one.back() >= two.back()){
        answer++;
        free += one.back();
        one.pop_back();
    }
    if(free >= m){
        cout << answer << "\n";
        return;
    }
    while(free < m){
        if(!one.empty()){
            if(one.back() + free >= m){
                cout << answer+1 << "\n";
                return;
            }
        }
        if(one.size() >= 2){
            long long int tot = -100;
            if(!two.empty()){
                tot = two.back();
            }
            if(one.back() + one[one.size()-2] > tot){
                free += one.back() + one[one.size()-2];
                one.pop_back();
                one.pop_back();
                answer += 2;
            }
            else{
                free += two.back();
                two.pop_back();
                answer += 2;
            }
        }
        else{
            if(!two.empty()){
                answer += 2;
                free += two.back();
                two.pop_back();
            }
            else{
                answer++;
                free += one.back();
                one.pop_back();
            }
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