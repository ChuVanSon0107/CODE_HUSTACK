#include <bits/stdc++.h>
using namespace std;

const int maxN = 100001;
int n, m, s, t;
vector<pair<int, int>> adj[maxN];
const int INF = 1e9;

void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }
    cin >> s >> t;
}

void dijkstra(int s, int t){
    //store the distance from s to i;
    //initialize the beginning value is INF
    vector<int> d(n + 1, INF);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, s});
    vector<bool> visited(n + 1, false);

    while(Q.empty() == false){
        pair<int, int> top = Q.top();
        Q.pop();
        int distance = top.first;
        int v = top.second;

        if(visited[v] == false){
            visited[v] = true;
            for(auto it : adj[v]){
                int u = it.first;
                int w = it.second;
                if(d[u] > d[v] + w){
                    d[u] = d[v] + w;
                    Q.push({d[u], u});
                }
            }
        }
    }

    if(d[t] == INF){
        cout << -1 << endl;
    }

    else cout << d[t] << endl;

}


int main(){
    input();
    dijkstra(s, t);
    return 0;
}