#include <bits/stdc++.h>
using namespace std;

long long power(int x, int k, int m){
    if(k == 0) return 1;
    if(k == 1) return x;

    long long res = power(x, k / 2, m);
    if(k % 2 == 1){
        return (res * res * x) % m;
    }

    else return (res * res) % m;
}

long long hashOverString(string s, int m){
    int sSize = s.size();
    long long sum = 0;
    for(int i = 0; i < sSize; i++){
        sum = (sum + power(256, sSize - 1 - i, m) * (int)s[i]) % m;
    }

    return sum;
}

int main(){
    int n, m;
    cin >> n >> m;

    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        cout << hashOverString(s, m) << endl;
    }

    return 0;
}