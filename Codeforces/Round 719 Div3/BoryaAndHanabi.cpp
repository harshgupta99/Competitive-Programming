#include<bits/stdc++.h>
using namespace std;
#define int long long int
struct Card{
    int color;
    int digit;
};
int n;
vector<Card> c;
int mapper(char z){
    if(z == 'R'){
        return 0;
    }
    else if(z == 'G'){
        return 1;
    }
    else if(z == 'B'){
        return 2;
    }
    else if(z == 'Y'){
        return 3;
    }
    return 4;
}
bool check(vector<bool> &digits_asked, vector<bool> &colors_asked){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(c[i].color != c[j].color){
                // check if color is asked 
                if(colors_asked[c[i].color] || colors_asked[c[j].color]){
                    continue;
                }
            }
            if(c[i].digit != c[j].digit){
                if(digits_asked[c[i].digit] || digits_asked[c[j].digit]){
                    continue;
                }
            }
            if(c[i].color == c[j].color && c[i].digit == c[j].digit){
                continue;
            }
            return false;
        }
    }
    return true;   
}
signed main(){
    set<pair<int, int> > s;
    cin >> n;
    c.resize(n);
    for(int i = 0; i < n; i++){
        char z;
        cin >> z >> c[i].digit;
        c[i].digit--;
        c[i].color = mapper(z);
        s.insert(make_pair(c[i].color, c[i].digit));
    }
    if((int)s.size() == 1LL){
        cout << "0\n";
        return 0;
    }
    int answer = 1e9;
    int limit = (1 << 10);
    for(int mask = 0; mask < limit; mask++){
        vector<bool> colors_asked(5, false);
        vector<bool> digits_asked(5, false);
        int p = 0;
        for(int i = 0; i < 10; i++){
            if(mask & (1 << i)){
                if(i < 5LL){
                    digits_asked[i] = true;
                    p++;
                }
                else{
                    colors_asked[i-5] = true;
                    p++;
                }
            }
        }
        if(answer <= p){
            continue;
        }
        if(check(colors_asked, digits_asked)){
            answer = min(answer, p);
        }
    }
    cout << answer << "\n";
    return 0;
}