package P_STRING_MATCHING;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        String P = input.nextLine();
        String T = input.nextLine();

        int cnt = 0, id = 0, n = P.length(), m = T.length();

        while(id < m){
            id = T.indexOf(P, id);

            if(id != -1){
                cnt ++;
                id  += n;
            }
            else{
                break;
            }
        }
        System.out.println(cnt);
        input.close();
    }
}
