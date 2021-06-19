#include<bits/stdc++.h>
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> pos(n+1);
    vector<int> a(n+1);
    vector<pair<int, int> > operations;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    for(int i = 1; i <= n/2; i++){
        if(a[i] == i){
            continue;
        }
        if(2 * abs(i - pos[i]) >= n){
            operations.push_back(make_pair(i, pos[i]));
            int prv = pos[i];
            pos[a[i]] = pos[i];
            pos[i] = i;
            swap(a[i], a[prv]);
        }
        else if(2 * (n - pos[i]) >= n){
            operations.push_back(make_pair(pos[i], n));
            int prv = pos[i];
            pos[i] = n;
            pos[a[n]] = prv;
            swap(a[prv], a[n]);
            operations.push_back(make_pair(i, pos[i]));
            prv = pos[i];
            pos[a[i]] = pos[i];
            pos[i] = i;
            swap(a[i], a[prv]);
        }
        else{
            operations.push_back(make_pair(1, pos[i]));
            int prv = pos[i];
            pos[i] = 1;
            pos[a[1]] = prv;
            swap(a[prv], a[1]);
            operations.push_back(make_pair(pos[i], n));
            prv = pos[i];
            pos[i] = n;
            pos[a[n]] = prv;
            swap(a[prv], a[n]);
            operations.push_back(make_pair(i, pos[i]));
            prv = pos[i];
            pos[a[i]] = pos[i];
            pos[i] = i;
            swap(a[i], a[prv]);
        }
        
    }
    for(int i = n/2 + 1; i <= n; i++){
        if(a[i] == i){
            continue;
        }
        if(2 * abs(i - pos[i]) < n){
            operations.push_back(make_pair(1, pos[i]));
            int prv = pos[i];
            pos[a[1]] = pos[i];
            pos[i] = 1;
            swap(a[1], a[prv]);
        }
        if(a[i] == i){
            continue;
        }
        operations.push_back(make_pair(1, i));
        pos[a[i]] = 1;
        pos[i] = i;
        swap(a[1], a[i]);
    }
    cout << (int)operations.size() << "\n";
    for(int i = 0; i < (int)operations.size(); i++){
        cout << operations[i].first << " " << operations[i].second << "\n";
        assert(2 * abs(operations[i].first - operations[i].second) >= n);
    }
    return 0;
}
