import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = scanner.nextInt();
        }

        long sum = 0, res = 0;

        for(int i = 0; i < n; i++){
            sum += a[i];
            if(sum > 0){
                res = Math.max(res, sum);
            }
            else if(sum < 0){
                sum = 0;
            }
        }

        System.out.println(res);

        scanner.close();
    }
}