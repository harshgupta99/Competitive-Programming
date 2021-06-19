#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;
    deque<deque<int> > a(n, deque<int> (m));
    multiset<pair<int, int> > s;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            s.insert(make_pair(a[i][j], i));
        }
        sort(a[i].begin(), a[i].end());
    }
    // for(auto x : s){
    //     cout << x.first << " " << x.second << "\n";
    // }
    // return;
    vector<vector<int> > runners(n);
    while(!s.empty()){
        pair<int, int> curr = *s.begin();
        s.erase(s.begin());
        // take minimum of curr.second and max of everyone else
        for(int j = 0; j < n; j++){
            if(j == curr.second){
                // cout << a[j].front() << " ";
                runners[j].push_back(a[j].front());
                a[j].pop_front();
                //s.erase(make_pair(a[j].front(), j));
            }
            else{
                // cout << a[j].back() << " ";
                runners[j].push_back(a[j].back());
                s.erase(s.find(make_pair(a[j].back(), j)));
                a[j].pop_back();
            }
        }
        // for(auto x : s){
        //     cout << x.first << " " << x.second << "\n";
        // }
        //return;
    }
    for(auto x : runners){
        for(auto y : x){
            cout << y << " ";
        }
        cout << "\n";
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}