//https://codeforces.com/gym/102873/problem/E
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    cin >> t;
    long long int answer = 0LL;
    vector<int> pos;
    for(int i = 0; i < n-1; i++){
        char _this = s[i];
        char _nxt = s[i+1];
        if(_this == t[0] && _nxt == t[1]){
            // add all previous and all next
            pos.push_back(i);
        }
    }
    if(pos.size() == 0){
        puts("0");
        return 0;
    }
    for(int i = 0; i < n; i++){
        vector<int>::iterator to_right = lower_bound(pos.begin(), pos.end(), i);
        if(to_right == pos.end()){
            break;
        }
        int Right = to_right - pos.begin();
        Right = pos[Right];
        Right++;
        // n - i - 1 substrings to the right
        long long int maybe = (long long int)(n - i - 1);
        maybe -= (long long int)(Right - i - 1);
        answer += maybe;
    }
    cout << answer << "\n";
    return 0;
}