#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, v, w;
};

int Size[100001];
int parent[100001];
vector<edge> ed;
int n, m;

void input(){
    cin >> n >> m;
    int u, v, w;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        edge e;
        e.u = u;
        e.v = v;
        e.w = w;
        ed.push_back(e);
    }
}

void make_set(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        Size[i] = 1;
    }  
}

int find(int v){
    if(v == parent[v]) return v;

    return parent[v] = find(parent[v]);
}

bool Union(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v){
        return false;
    }

    else{
        if(Size[u] < Size[v]){
            int tmp = Size[u];
            Size[u] = Size[v];
            Size[v] = tmp;
        }

        Size[u] += Size[v];
        parent[v] = u;
        return true;
    }
}

bool cmp(edge a, edge b){
    return a.w < b.w;
}

void kruskal(){
    int mst = 0, cnt = 0;
    sort(ed.begin(), ed.end(), cmp);

    for(int i = 0; i < m; i++){
        if(cnt == n - 1){
            //complete the spanning tree
            break;
        }

        edge a = ed[i];

        if(Union(a.u, a.v) == true){
            cnt ++;
            mst += a.w;
        }
    }

    cout << mst << endl;
}

int main(){

    input();
    make_set();
    kruskal();

    return 0;

}