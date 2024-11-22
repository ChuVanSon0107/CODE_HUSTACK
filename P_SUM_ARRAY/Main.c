#include <stdio.h>


int main(){
    int n, x;
    scanf("%d", &n); 
    long long sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        sum += x;
    }
    printf("%lld", sum);
    return 0;
}