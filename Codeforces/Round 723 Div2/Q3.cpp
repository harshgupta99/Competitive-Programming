#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<long long int> t(4*N), lazy(4*N);
vector<long long int> a(N), pref(N);
void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = pref[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = min(t[2*v], t[2*v+1]);
    }
}
void update(int v, int tl, int tr, int l, int r, long long int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

long long int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 1e18;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
void solve(){
	int n;
	scanf("%d", &n);
	vector<pair<long long int, int> > neg;
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		if(a[i] < 0LL)
			neg.push_back({a[i], i});
		pref[i] = max(0LL, a[i]);
		if(i)
			pref[i] += pref[i-1];
	}
	int answer = n - (int)neg.size();
	sort(neg.begin(), neg.end());
	build(1, 1, n);
	// try to pick greedily
	while(!neg.empty()){
		pair<long long int, int> curr = neg.back();
		neg.pop_back();
		long long int mn = query(1, 1, n, curr.second, n);
		if(abs(curr.first) <= mn){
			// possible
			++answer;
			update(1, 1, n, curr.second, n, curr.first);
			// for(int i = curr.second; i < n; i++)
			// 	pref[i] += curr.first;
		}
	}
	printf("%d\n", answer);
	return;
}
int main(){
	int test_cases = 1;
	while(test_cases--) solve();
}