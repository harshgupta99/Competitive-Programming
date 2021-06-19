#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<pair<int, int> > answer;
    int divisor = (n + 1) / 2;
    vector<int> D;
    int num = n;
    while(num != 3){
        D.push_back(divisor);
        while(num != divisor && num != 3){
            answer.push_back(make_pair(num, num-1));
            num--;
        }
        divisor = (num + 1) / 2;
        num--;
    }
    D.push_back(2);
    for(int i = 0; i < D.size()-1; i++){
        answer.push_back(make_pair(D[i], D[i+1]));
        answer.push_back(make_pair(D[i], 2));
    }
    //assert((int)answer.size() <= n + 5);
    cout << (int)answer.size() << "\n";
    for(int i = 0; i < (int)answer.size(); i++){
        cout << answer[i].first << " " << answer[i].second << "\n";
    }
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}