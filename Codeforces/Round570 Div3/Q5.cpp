#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    set<string> visited;
    queue<string> q;
    q.push(s);
    visited.insert(s);
    int ans = 0;
    while(!q.empty() && (int)visited.size() < k){
        string v = q.front();
        q.pop();
        for(int i = 0; i < (int)v.size(); i++){
            string tmp = v;
            tmp.erase(i, 1);
            if(!visited.count(tmp) && visited.size() + 1 <= k){
                q.push(tmp);
                visited.insert(tmp);
                ans += n - tmp.size();
            }
        }
    }
    if(visited.size() < k){
        cout << "-1\n";
        return 0;
    }
    cout << ans << "\n";
    return 0;
}