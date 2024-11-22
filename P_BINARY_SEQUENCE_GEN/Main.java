package P_BINARY_SEQUENCE_GEN;

import java.util.Scanner;

public class Main {

    public static void printArray(int[] array){
        for(int x : array){
            System.out.print(x);
        }
        System.out.println();
    }

    public static void backtracking(int id, int n, int[] array){
        if(id == n){
            printArray(array);
            return;
        }

        for(int i = 0; i <= 1; i++){
            array[id] = i;
            backtracking(id + 1, n, array);
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] array = new int[n];

        backtracking(0, n, array);

        input.close();
    }
}
