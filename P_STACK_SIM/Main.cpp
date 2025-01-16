#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int> myStack;
    string a[2];
    string x;
    while(true){
        getline(cin, x);
        if(x == "#"){
            break;
        }

        stringstream ss(x);
        string tmp;
        int i = 0;
        while(ss >> tmp){
            a[i] = tmp;
            i ++;
        }

        if(a[0] == "PUSH"){
            myStack.push(stoi(a[1]));
        }
        else if(a[0] == "POP"){
            if(myStack.empty() == true){
                cout << "NULL" << endl;
            }
            else{
                cout << myStack.top() << endl;
                myStack.pop();
            }
        }
    }
    return 0;
}