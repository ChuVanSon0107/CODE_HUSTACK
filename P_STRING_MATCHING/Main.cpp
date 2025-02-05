#include <bits/stdc++.h>
using namespace std;



int main(){
    string s, t;
    getline(cin, s);
    getline(cin, t);
    int cnt = 0;
    int id = -1;
    int m = s.size();
    
    while(true){
        id = t.find(s);
        if(id == string::npos){
            break;
        }

        cnt ++;
        t = t.substr(id + m);
    }

    cout << cnt << endl;
}
