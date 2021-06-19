//https://codeforces.com/gym/102873/problem/D
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int a, s;
    cin >> a >> s;
    long long int need = s - a;
    if(need <= 0){
        puts("NO");
        return 0;
    }
    vector<int> digits;
    while(a){
        digits.push_back(a%10);
        a /= 10;
    }
    vector<int> need_digits;
    while(need){
        need_digits.push_back(need%10);
        need /= 10;
    }
    sort(digits.begin(), digits.end());
    sort(need_digits.begin(), need_digits.end());
    if(need_digits.size() != digits.size()){
        puts("NO");
        return 0;
    }
    for(int i = 0; i < (int)digits.size(); i++){
        if(digits[i] != need_digits[i]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}