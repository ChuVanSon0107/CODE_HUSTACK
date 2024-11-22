import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        @SuppressWarnings("resource")
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int x, sum = 0, i;
        for(i = 0; i < n; i++){
            x = input.nextInt();
            sum += x;
        }
        input.close();
        System.out.println(sum);
    }
}