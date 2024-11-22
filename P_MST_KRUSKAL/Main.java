package P_MST_KRUSKAL;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Krukal a = new Krukal();
        a.input();
        a.make_set();
        a.krukal();
    }   
}
class Krukal {
    private int n, m;
    private int[] parent = new int[100005];
    private int[] size = new int[100005];
    private ArrayList<Edge> edge = new ArrayList<>();

    public void make_set(){
        for(int i = 1; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    public int find(int v) {
        if(v == parent[v]){
            return v;
        }

        return parent[v] = find(parent[v]);
    }

    public boolean Union(int a, int b){
        a = find(a);
        b = find(b);

        if(a == b){
            return false;
        }

        else{
            if(size[a] < size[b]){
                int x = size[a];
                size[a] = size[b];
                size[b] = x;
            }
            parent[b] = a;
            size[a] += size[b];
            return true;
        }

    }

    public void input(){
        Scanner input = new Scanner(System.in);
        n = input.nextInt();
        m = input.nextInt();

        int x, y, w;
        for(int i = 0; i < m; i++){
            x = input.nextInt();
            y = input.nextInt();
            w = input.nextInt();

            edge.add(new Edge(x, y, w));
        }

        input.close();
    }

    public void krukal(){
        int mst = 0, cnt = 0;

        Collections.sort(edge, new ComparatorByWeight());

        for(int i = 0; i < m; i++){
            if(cnt == n - 1){
                break;
            }

            Edge e = edge.get(i);

            if(Union(e.u, e.v) == true){
                cnt ++;
                mst += e.w;
            }
        }


        System.out.println(mst);
    }

}

class ComparatorByWeight implements Comparator<Edge> {

    @Override
    public int compare(Edge a, Edge b) {
        return a.w - b.w;
    }

}

class Edge {

    int u, v, w;

    public Edge (){

    }

    public Edge(Edge e){
        u = e.u;
        v = e.v;
        w = e.w;
    }

    public Edge(int u, int v, int w){
        this.u = u;
        this.v = v;
        this.w = w;
    }
}
