#include <stdio.h>
#include<string.h>

int main(){
    char a[20], b[20], sum[20];
    scanf("%s %s", a, b);

    int i = 0, x = 0;
    int n = strlen(a), m = strlen(b);
    
    while(n > 0 && m > 0){
        n --;
        m --;

        x = x + (a[n] - '0') + (b[m] - '0');

        if(x < 10){
            sum[i] = (x + '0');
            x = 0;
        }
        else{
            sum[i] = (x - 10 + '0');
            x = 1;
        }
        i++;
    }

    while(n > 0){
        n --;

        if(x == 1){
            x = 0;
            sum[i] = a[n] + 1;
        }
        else{
            sum[i] = a[n];
        }

        i++;
    }

    while(m > 0){
        m --;
        if(x == 1){
            x = 0;
            sum[i] = b[m] + 1;
        }
        else{
            sum[i] = b[m];
        }
        i ++;
    }

    if(x == 1){
        sum[i] = '1';
        i ++;
    }


    for(int k = i - 1; k >= 0; k--){
        printf("%c", sum[k]);
    }

    return 0;
}