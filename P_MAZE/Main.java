package P_MAZE;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        FindPath a = new FindPath();
        a.nhap();
        a.findPath();
    }
}

class FindPath {
    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};
    int n, m, r, c;
    int[][] path;
    int[][] maze;

    public void nhap(){
        Scanner input = new Scanner(System.in);
        n = input.nextInt();
        m = input.nextInt();
        r = input.nextInt();
        c = input.nextInt();

        maze = new int[n][m];
        path = new int[n][m];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                maze[i][j] = input.nextInt();
                path[i][j] = 0;
            }
        }
        input.close();
    }

    public void findPath(){
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(r - 1, c - 1));
        maze[r - 1][c - 1] = 1;
        path[r - 1][c - 1] = 1;

        Pair a;
        while(q.isEmpty() == false){
            a = q.poll();
            for(int k = 0; k < 4; k++){
                int x = a.x + dx[k];
                int y = a.y + dy[k];

                if(0 <= x && x < n && 0 <= y && y < m && maze[x][y] == 0){
                    maze[x][y] = 1;
                    path[x][y] = path[a.x][a.y] + 1;
                    q.add(new Pair(x, y));
                }
            }
        }

        int max = Integer.MAX_VALUE;

        for(int i = 0; i < n; i++){
            if(path[i][0] != 0){
                max = Math.min(max, path[i][0]);
            }
            if(path[i][m - 1] != 0){
                max = Math.min(max, path[i][m - 1]);
            }
        }
        for(int i = 0; i < m; i++){
            if(path[0][i] != 0){
                max = Math.min(max, path[0][i]);
            }
            if(path[n - 1][i] != 0){
                max = Math.min(max, path[n - 1][i]);
            }
        }
        if(max == Integer.MAX_VALUE){
            System.out.println(-1);
        }
        else System.out.println(max);
    }

}

class Pair {
    int x, y;

    public Pair(int x, int y){
        this.x = x;
        this.y = y;
    }
}
