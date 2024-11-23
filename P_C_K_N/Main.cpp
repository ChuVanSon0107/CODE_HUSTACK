#include <bits/stdc++.h>
using namespace std;

int const MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> k >> n;
    int c[n + 1][n + 1];
    for(int i = 0; i < n; i++){
        c[i][0] = 1;
        c[i][i] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            c[i][j] = (c[i - 1][j - 1] % MOD  + c[i - 1][j] % MOD) % MOD;
        }
    }
    
    cout << c[n][k];

    return 0;
}