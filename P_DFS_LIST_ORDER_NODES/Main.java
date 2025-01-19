package P_DFS_LIST_ORDER_NODES;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        DFS a = new DFS();
        a.input();
        a.dfs(1);
    }
}

class DFS {
    private int n;
    private ArrayList<Integer>[] adj;
    private boolean[] visited;
    public DFS(){
    
    }

    @SuppressWarnings("unchecked")
    public void input(){
        Scanner input = new Scanner(System.in);
        this.n = input.nextInt();
        adj = new ArrayList[n + 1];
        visited = new boolean[n + 1];
        for(int i = 1; i <= n; i++){
            adj[i] = new ArrayList<>();
            visited[i] = false;
        }
        int m = input.nextInt();

        int x, y;
        while(m > 0){
            m --;
            x = input.nextInt();
            y = input.nextInt();
            adj[x].add(y);
            adj[y].add(x);
        }
        input.close();
    }

    public void dfs(int i){
        visited[i] = true;
        System.out.print(i + " ");

        for(int x : adj[i]){
            if(visited[x] == false){
                dfs(x);
            }
        }
    }
}
