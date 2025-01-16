package P_STACK_SIM;

import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        Scanner input = new Scanner(System.in);

        String x;
        String[] a = new String[2];
        while(true){
            x = input.nextLine();

            if(x.equals("#")) break;

            a = x.split(" ");

            if(a[0].equals("PUSH")){
                stack.push(Integer.parseInt(a[1]));
            }
            else if(a[0].equals("POP")){
                if(stack.isEmpty()){
                    System.out.println("NULL");
                }
                else{
                    System.out.println(stack.pop());
                }
            }
        }

        input.close();
        System.exit(0);
    }
}