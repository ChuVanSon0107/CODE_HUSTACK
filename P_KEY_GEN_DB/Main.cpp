#include <bits/stdc++.h>
using namespace std;

int n, L, m;
string temp, s;
map<string, int> mp;

void input(){
    cin >> n >> L >> m;
    for(int i = 0; i < n; i++){
        cin >> temp;
        mp[temp] = 1;
    }

    //initialize the string
    for(int i = 0; i < L; i++){
        s += '0';
    }

}

void generateKey(int &cnt){
    //Da xay dung du key
    if(cnt == 0) return;

    //Truong hop chua du
    int i = L - 1;
    while(i >= 0 && s[i] == '9'){
        i --;
    }

    s[i] = (s[i] + 1);

    for(int j = i + 1; j < L; j++){
        s[j] = '0';
    }

    if(mp[s] == 0){
        mp[s] = 1;
        cnt--;
    }
    
    generateKey(cnt);

}

void printKey(){
    for(auto x : mp){
        cout << x.first << endl;
    }
}

int main(){
    input();
    generateKey(m);
    printKey();
    return 0;
}