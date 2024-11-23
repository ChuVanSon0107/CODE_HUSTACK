package P_C_K_N;

import java.util.Scanner;

public class Main {

    public static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int k = input.nextInt();
        int n = input.nextInt();
        input.close();

        int[][] c = new int[n + 1][n + 1];

        for(int i = 0; i <= n; i++){
            c[i][0] = 1;
            c[i][i] = 1;
        }

        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++){
                c[i][j] = ((c[i - 1][j] % MOD) + (c[i - 1][j - 1]) % MOD) % MOD;
            }
        }

        System.out.println(c[n][k]);

    }   
}
