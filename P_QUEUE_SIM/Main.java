package P_QUEUE_SIM;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String[] a = new String[2];
        String b;
        Queue<Integer> queue = new LinkedList<>();

        while(true){
            b = input.nextLine();

            if(b.equals("#")){
                break;
            }

            a = b.split(" ");
            
            if(a[0].equals("PUSH")){
                queue.add(Integer.parseInt(a[1]));
            }
            else if(a[0].equals("POP")){
                if(queue.isEmpty()){
                    System.out.println("NULL");
                }
                else{
                    System.out.println(queue.poll());
                }
            }
        }
        input.close();

        System.exit(0);
    }
}
