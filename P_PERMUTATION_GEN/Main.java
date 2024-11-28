package P_PERMUTATION_GEN;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Permutation a = new Permutation();
        a.input();
        a.initPermutation();
        a.genPermutation();
    }
}

class Permutation {
    private int n;
    private int[] a;

    public void input(){
        Scanner input = new Scanner(System.in);
        n = input.nextInt();
        a = new int[n];
        input.close();
    }

    public void initPermutation(){
        for(int i = 0; i < n; i++){
            a[i] = i + 1;
        }
    }

    public void printPermutation(){
        for(int i = 0; i < n; i++){
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }

    public void genPermutation(){
        boolean lastPermutation = false;
        
        //The first permutation
        printPermutation();
        int i, j, t;

        //Find the next permutation
        while(lastPermutation == false){

            //find the first index where a[i] < a[i + 1]
            i = n - 2;
            while(i >= 0 && a[i] >= a[i + 1]){
                i --;
            }

            if(i == -1){
                lastPermutation = true;
            }

            else{
                //find the last index where a[j] > a[i]
                j = n - 1;
                while(a[j] <= a[i]){
                    j --;
                }

                

                //swap a[i] and a[j]
                t = a[i];
                a[i] = a[j];
                a[j] = t;

                //reverse array from index i + 1 to n - 1
                j = n - 1;
                i = i + 1;
                while(i < j){
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                    i ++;
                    j--;    
                }

                printPermutation();
            }
            
        }
    }
}
