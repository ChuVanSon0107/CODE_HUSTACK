#include <stdio.h>
#include <stdlib.h>

void merge(int* a, int l, int m, int r){
    int lsize = m - l + 1, rsize = r - m;
    int L[lsize], R[rsize];

    for(int i = 0; i < lsize; i++){
        L[i] = a[l + i];
    }

    for(int i = 0; i < rsize; i++){
        R[i] = a[m + i + 1];
    }

    int i = 0, j = 0;
    while(i < lsize && j < rsize){
        if(L[i] < R[j]){
            a[l] = L[i];
            l ++;
            i++; 
        }
        else{
            a[l] = R[j];
            l ++;
            j++;
        }
    }

    while(i < lsize){
        a[l] = L[i];
        l++;
        i++;
    }
    
    while(j < rsize){
        a[l] = R[j];
        l++;
        j++;
    }
}

void mergeSort(int* a, int l, int r){
    if(l < r){
        int m = (r - l) / 2 + l;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int) + 1);

    for(int i = 0; i < n; i++){
        scanf("%d", a + i);
    }

    mergeSort(a, 0, n - 1);

    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    free(a);
}