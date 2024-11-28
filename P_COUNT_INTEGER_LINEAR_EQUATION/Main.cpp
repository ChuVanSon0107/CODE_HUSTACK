#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1000];
int cnt = 0;

void input(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void solve(int i, int sum){
    if(sum == 0 && i == n){
        cnt ++;
    }
    else if(sum > 0 && i < n){
        int j = sum / a[i];
        for(int k = 1; k <= j; k++){
            solve(i + 1, sum - k * a[i]);
        }
    }
    else return;
}

int main () {
    input();
    solve(0, m);
    cout << cnt << endl;
    return 0;
}