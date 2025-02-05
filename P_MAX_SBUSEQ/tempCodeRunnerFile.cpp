#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    long sum = 0, res = 0;

    for(int i = 0; i < n; i++){
        sum += a[i];

        if(sum > 0){
            res = max(res, sum);
        }

        else if(sum < 0){
            sum = 0;
        }
    }

    cout << res << endl;
    return 0;
}