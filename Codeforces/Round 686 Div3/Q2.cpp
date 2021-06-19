//https://codeforces.com/contest/1454/problem/C
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<vector<int> > a(n+1);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        a[x].push_back(i);
    }
    if(n == 1){
        puts("0");
        return;
    }
    int answer = 1e9;
    for(int i = 1; i <= n; i++){
        int this_answer = 0;
        if(a[i].size() == 0){
            continue;
        }
        for(int j = 0; j < a[i].size(); j++){
            if(j == 0 && a[i][j] != 1){
                ++this_answer;
            }
            if(j+1 < (a[i].size())){
                int val = a[i][j+1] - a[i][j];
                if(val > 1){
                    ++this_answer;
                }
            }
            else{
                if(a[i][j] != n){
                    ++this_answer;
                }
            }
        }
        //cout << i << " " << this_answer << "\n";
        answer = min(answer, this_answer);
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