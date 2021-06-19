#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    if((int)s.size() <= 2){
        cout << "YES\n";
        return 0;
    }
    int f = int(s[0] - 'A');
    int se = int(s[1] - 'A');
    for(int i = 2; i < (int)s.size(); i++){
        if((s[i]-'A') != (f + se)%25){
            cout << "NO\n";
            return 0;
        }
        f = se;
        se = (s[i] - 'A');
    } 
    cout << "YES\n";
    return 0;
}