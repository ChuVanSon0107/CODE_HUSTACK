#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> myQueue;
    string a[2];
    string b;

    while(true){
        getline(cin, b);

        if(b == "#"){
            break;
        }

        string tmp;
        stringstream ss(b);
        int i = 0;
        while(ss >> tmp){
            a[i] = tmp;
            i ++;
        }

        if(a[0] == "PUSH"){
            myQueue.push(stoi(a[1]));
        }

        else if(a[0] == "POP"){
            if(myQueue.empty() == true){
                cout << "NULL" << endl;
            }
            else{
                cout << myQueue.front() << endl;
                myQueue.pop();
            }
        }
    }
    return 0;
}