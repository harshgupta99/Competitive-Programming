#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<long long int> a(n);
    map<long long int, vector<int> > mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    vector<int> group(n, -1);
    sort(a.begin(), a.end());
    int q;
    cin >> q;
    long long int answer = 0;
    int cnt = 0;
    vector<int> A(1e3+10, 0);
    int T = 0;
    while(T <= 5){
        for(long long int i = 0; i < n; i++){
            long long int curr = 0;
            if(group[i] != -1){
                continue;
            }
            long long int E = 1LL;
            vector<int> G;
            for(long long int z = 1; z*z <= 1e6; z++){
                if(mp.find(a[i]*z*z) != mp.end()){
                    for(int j = 0; j < mp[a[i]*z*z].size(); j++){
                        group[mp[a[i]*z*z][j]] = cnt;
                        ++curr;
                        G.push_back(mp[a[i]*z*z][j]);
                        E *= (long long int)a[i]*z*z;
                    }
                }
            }
            for(int j = 0; j < G.size(); j++){
                a[G[j]] = E;
            }
            //cout << E << "\n";
            answer = max(answer, curr);
            ++cnt;
        }
        mp.clear();
        for(int i = 0; i < n; i++){
            mp[a[i]].push_back(i);
        }
        group = vector<int> (n, -1);
        A[T++] = answer;
        cnt = 0;
    }
 //cout << A[0] << "\n";
    while(q--){
        int c;
        cin >> c;
        if(c <= 1e3){
            cout << A[c] << "\n";
        }
        else{
            cout << A.back() << "\n";
        }
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