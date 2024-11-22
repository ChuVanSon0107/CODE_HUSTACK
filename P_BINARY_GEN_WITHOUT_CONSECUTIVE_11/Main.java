package P_BINARY_GEN_WITHOUT_CONSECUTIVE_11;

import java.util.Scanner;

public class Main {

    public static void backtracking(int id, int[] arr, int n, boolean existOne){

        if(id == n){
            for(int i = 0; i < n; i++){
                System.out.print(arr[i]);
            }
            System.out.println();
            return;
        }

        for(int i = 0; i <= 1; i++){
            arr[id] = i;
            
            //exist 11
            if(existOne == true && i == 1){
                return;
            }
            
            //don't exist 11
            if(i == 1){
                backtracking(id + 1, arr, n, true);
            }
            else{
                backtracking(id + 1, arr, n, false);
            }

        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        backtracking(0, arr, n, false); 
        scanner.close();
    }
}
