#include <bits/stdc++.h>
using namespace std;

void backtracking(int id, int a[], int n, bool existOne){
    if(id == n){
        for(int i = 0; i < n; i++){
            cout << a[i];
        }
        cout << endl;
        return;
    }

    for(int i = 0; i <= 1; i++){
        a[id] = i;

        //exist 11
        if(existOne == true && i == 1){
            return;
        }

        //don't exist 11
        if(i == 1){
            backtracking(id + 1, a, n, true);
        }

        else{
            backtracking(id + 1, a, n, false);
        }
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    backtracking(0, a, n, false);

    return 0;
}