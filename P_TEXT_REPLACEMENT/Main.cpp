#include <bits/stdc++.h>
using namespace std;

int main(){
    string p1, p2, T;
    getline(cin, p1);
    getline(cin, p2);
    getline(cin, T);

    int p1Size = p1.size(), p2Size = p2.size(), Tsize = T.size();
    int i = 0, j = 0, temp;
    bool finalWord = false;//check xem tu cuoi cung co phai la p1 hay khong
    while(i < Tsize  - p1Size + 1){
        if(T[i] != p1[j]){
            cout << T[i];
            i++;
            finalWord = false;
        }
        else{
            temp = i + 1;
            j ++;
            while(j < p1Size){
                if(T[temp] != p1[j]){
                    break;
                }
                else{
                    temp ++;
                    j ++;
                }
            }

            if(j == p1Size){
                finalWord = true;
                cout << p2;
                i = temp;
            }
            j = 0;

        }
    }
    
    if(finalWord == false){
        while(i < Tsize){
            cout << T[i];
            i++;
        }
    }

    return 0;
}