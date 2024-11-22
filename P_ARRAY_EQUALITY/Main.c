//C 
#include <stdio.h> 
#include <stdbool.h>

int main() 
{ 
    int t;
    scanf("%d",&t);
    int n, m, a[2000], x;
    bool result;
    while(t--){
        scanf("%d %d",&n, &m);
        result = false;
        if(n == m){
            result = true;
            for(int i = 0; i < n; i++){
                scanf("%d", a + i);
            }
            
            for(int i = 0; i < n; i++){
                scanf("%d", &x);
                if(x != a[i]){
                    result = false;
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                scanf("%d", &x);
            }
            
            for(int i = 0; i < n; i++){
                scanf("%d", &x);
            }
        }
        if(result == true){
            printf("%d\n", 1);
        }
        else{
            printf("%d\n", 0);
        }
    }
}