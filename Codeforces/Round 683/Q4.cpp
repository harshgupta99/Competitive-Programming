#include<bits/stdc++.h>
using namespace std;
int lcs(string X, string Y, int m, int n){  
    int L[m + 1][n + 1];  
    int i, j;  
    for (i = 0; i <= m; i++){  
        for (j = 0; j <= n; j++){  
            if(i == 0 || j == 0){  
                L[i][j] = 0;  
            }
            else if (X[i - 1] == Y[j - 1]){  
                L[i][j] = L[i - 1][j - 1] + 2;  
            }
            else{
                L[i][j] = max(L[i - 1][j]-1, L[i][j - 1]-1);  
                L[i][j] = max(0, L[i][j]);
            }
        }  
    }  
    int maxy = 0;
    bool ok = false;
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            ok |= (L[i][j] > 0);
           maxy = max(maxy, L[i][j]);
        }
    }
    if(!ok){
        return 0;
    }
    return maxy;
}  
int main() {
    int n, m;
    cin >> n >> m;
	string x, y;
	cin >> x >> y;
	cout << lcs(x, y, n, m);
	return 0;
}
