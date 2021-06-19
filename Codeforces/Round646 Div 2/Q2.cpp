#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin >> s;
    // either all of one kind or all 0s together and all 1s together
    char curr = s[0];
    int swaps= 0;
    int len = 1;
    for(int i = 1; i< s.size();){
        int index = i;
        while(s[index] == curr && index < s.size()){
            len++;
            index++;
        }
        if(index == s.size()){
            break;
        }
        char curr2 = s[index];
        int len2 = 1;
        while(index + 1 < s.size() && s[index+1] == curr2){
            len2++;
            index++;
        }
        if(index == s.size()-1){
            break;
        }
        if(len > len2){
            swaps += len2;
            len += len2;
        }
        else{
            swaps += len;
            len = 0;
            curr = curr2;
        }
        if(index == i){
            i++;
        }
        else{
            i = index;
        }
    }
    cout<<swaps<<"\n";
}
int main(){
    int t;
    cin >>t;
    while(t--){
        solve();
    }
}
