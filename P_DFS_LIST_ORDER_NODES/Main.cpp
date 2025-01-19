#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1000];
vector<bool> visited(1000, false);

void input(){
    cin >> n >> m;
    while(m --){
        int  x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void dfs(int i){
    visited[i] = true;
    cout << i << " ";

    for(int x : adj[i]){
        if(visited[x] == false){
            dfs(x);
        }
    }
}

int main(){
    input();
    dfs(1);
    return 0;
}