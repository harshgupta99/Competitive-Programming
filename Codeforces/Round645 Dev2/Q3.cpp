#include<bits/stdc++.h>
using namespace std;
struct node{
    int row;
    int col;
    long long int cost;
    int type;
    long long int upd;
    node(int a, int b, long long int c){
        row = a;
        col = b;
        cost = (c%1000000007);
    }
};
long long int previous_update_row;
long long int previous_update_col;
long long int calc_cost(int x,int y){
    long long int cost = 1;
    int col = 1;
    int row = 1;
    int prev_upd = 2;
    while(row < x){
        cost += prev_upd;
        prev_upd++;
        row++;
    }
    previous_update_row = prev_upd;
    prev_upd = row;
    while(col < y){
        cost += prev_upd;
        prev_upd++;
        col++;
    }
    previous_update_col = prev_upd;
    return cost;
}
long long int bfs(int x1, int y1, int x2, int y2){
    queue<node>q;
    q.push(node(x1, y1, calc_cost(x1, y1)));
    set<long long int> s;
    while(!q.empty()){
        node curr = q.front();
        q.pop();
        if(curr.row == x2 && curr.col == y2){
            // cout<<curr.cost<<"\n";
            s.insert(curr.cost);
        }
        if(curr.row < x2){
            q.push(node(curr.row+1, curr.col, curr.cost + previous_update_row));
        }
        if(curr.col < y2){
            q.push(node(curr.row, curr.col + 1, curr.cost + previous_update_col)); 
        }
        previous_update_row++;
        previous_update_col++;
    }
    return s.size();
}
void solve(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long int count = bfs(x1, y1, x2, y2);
    cout<<count<<"\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}