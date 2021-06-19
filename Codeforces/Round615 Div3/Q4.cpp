#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    vector<int> mods(n);
    set<pair<int, int> > vals;
    for(int i = 0 ; i < q; i++){
        vals.insert(make_pair(mods[i], i));
    }
    for(int i = 0; i < n; i++){
        int curr;
        cin >> curr;
        curr %= q;
        vals.erase(make_pair(mods[curr], curr));
        mods[curr]++;
        vals.insert(make_pair(mods[curr], curr));
        cout << vals.begin()->first * q + vals.begin()->second << "\n";
    }
    return 0;
}