#include <bits/stdc++.h>
using namespace std;

int n;

void input(){
    cin >> n;
}

void print(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i];
    }
    cout << endl;
}

void backtracking(int id, int n, int a[]){
    if(id == n){
        print(a, n);
        return;
    }

    for(int i = 0; i <= 1; i++){
        a[id] = i;
        backtracking(id + 1, n, a);
    }
}

int main(){
    
    input();
    int a[n];
    backtracking(0, n, a);

    return 0;

}