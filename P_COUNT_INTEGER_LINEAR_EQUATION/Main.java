package P_COUNT_INTEGER_LINEAR_EQUATION;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Equation a = new Equation();
        a.input();
        a.solveProblem();
    }
}

class Equation {
    private int n;
    private int[] a;
    private int m;
    private int cnt;

    public void input(){
        Scanner input = new Scanner(System.in);
        n = input.nextInt();
        m = input.nextInt();
        cnt = 0;
        a = new int[n];

        for(int i = 0; i < n; i++){
            a[i] = input.nextInt();
        }
        input.close();
    }

    public void solve(int i, int sum){
        if(sum == 0 && i == n){
            cnt ++;
        }
        
        else if(sum > 0 && i < n){
            int j = sum / a[i];
            for(int k = 1; k <= j; k++){
                solve(i + 1, sum - k * a[i]);
            }
        }

        else return;
    }

    public void solveProblem(){
        solve(0, m);
        printResult();
    }

    public void printResult(){
        System.out.println(cnt);
    }
}

