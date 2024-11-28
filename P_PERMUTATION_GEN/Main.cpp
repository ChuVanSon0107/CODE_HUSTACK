#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000];

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        a[i] = i + 1;
    }
}

void printPermutation(){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void genPermutation(){
    bool lastPermutation = false;   
    printPermutation();

    int i, j;

    while(lastPermutation == false){
        i = n - 2;
        while(i >= 0 && a[i] >= a[i + 1]){
            i --;
        }

        if(i == -1){
            lastPermutation = true;
        }

        else{
            j = n - 1;
            while(a[i] >= a[j]){
                j --;
            }

            swap(a[i], a[j]);

            i = i + 1;
            j = n - 1;
            while(i < j){
                swap(a[i], a[j]);
                i ++;
                j --;
            }

            printPermutation();
        }
    }
}

int main(){
    input();
    genPermutation();
    return 0;
}