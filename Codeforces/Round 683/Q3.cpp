//https://codeforces.com/contest/1447/problem/C
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    long long int W;
    cin >> n >> W;
    vector<pair<long long int, int> > weights(n);
    long long int sum = 0LL;
    bool ok = false;
    long long int miny = (W + 1)/2;
    int idx = -1;
    for(int i = 0; i < n; i++){
        cin >> weights[i].first;
        sum += weights[i].first;
        if(weights[i].first >= miny && weights[i].first <= W){
            idx = i+1;
        }
        weights[i].second = i+1;
    }
    if(sum < miny){
        puts("-1");
        return;
    }
    if(idx != -1){
        puts("1");
        cout << idx << "\n";
        return;
    }   
    sort(weights.begin(), weights.end());
    sum = 0LL;
    vector<int> answer;
    while(!weights.empty() && sum < miny){
        if(sum >= miny && sum <= W){
            break;
        }
        if(sum + weights.back().first <= miny){
            sum += weights.back().first;
            answer.push_back(weights.back().second);
        }
        else if(sum + weights.back().first <= W){
            sum += weights.back().first;
            answer.push_back(weights.back().second);
        }
        weights.pop_back();
    }
    if(sum >= miny && sum <= W){
        cout << answer.size() << "\n";
        for(int i = 0; i < (int)answer.size(); i++){
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }
    puts("-1");
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}