package P_LINKED_LIST_MANIPULATION;

import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        LinkedList<Integer> list = new LinkedList<>();
        int n = scanner.nextInt();
        for(int i = 0; i < n; i++){
            list.add(scanner.nextInt());
        }

        String s;
        String[] a = new String[3];
        int u, v, i, j;
        while(true){
            s = scanner.nextLine();
            if(s.equals("#") == true){
                break;
            }
            
            a = s.split(" ");

            if(a[0].equals("addfirst") == true){
                u = Integer.parseInt(a[1]);
                if(list.contains(u) == false){
                    list.addFirst(u);
                }
            }
            else if(a[0].equals("addlast") == true){
                u = Integer.parseInt(a[1]);
                if(list.contains(u) == false){
                    list.addLast(u);
                }
            }
            else if(a[0].equals("addafter") == true){
                u = Integer.parseInt(a[1]);
                v = Integer.parseInt(a[2]);
                i = list.indexOf(u);
                j = list.indexOf(v);

                if(i == -1 && j != -1){
                    list.add(j + 1, u);
                }
            }
            else if(a[0].equals("addbefore") == true){
                u = Integer.parseInt(a[1]);
                v = Integer.parseInt(a[2]);
                i = list.indexOf(u);
                j = list.indexOf(v);

                if(i == -1 && j != -1){
                    list.add(j, u);
                }
            }
            else if(a[0].equals("remove") == true){
                u = Integer.parseInt(a[1]);
                i = list.indexOf(u);
                if(i != -1){ 
                    list.remove(i);
                }
            }
            else if(a[0].equals("reverse") == true){
                LinkedList<Integer> revLinkedList = new LinkedList<>();
                for(int k = list.size() - 1; k >= 0; k--){
                    revLinkedList.add(list.get(k));
                }
                list = revLinkedList;
            }
        }

        for(int x : list){
            System.out.print(x + " ");
        }

        scanner.close();
    }
}
