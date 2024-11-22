package P_GOLD;

import java.util.Scanner;

public class Main {
    public int maxGold = 0;

    public void findGold(int id, int[] a, int n, int L1, int L2, int sum){
        for(int i = L1; i <= L2; i++){
            int k = id + i;
            if(k < n){
                sum += a[k];

                if(sum > maxGold){
                    maxGold = sum;
                }
                findGold(k, a, n, L1, L2, sum);
                sum -= a[k];
            }
            else{
                return;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int L1 = scanner.nextInt();
        int L2 = scanner.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = scanner.nextInt();
        }

        Main x = new Main();
        for(int i = 0; i < L1; i++){
            x.findGold(i, a, n, L1, L2, a[i]);
        }
        System.out.println(x.maxGold);

        scanner.close();
    }
}
