#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
int n;
vector<int> adj[MAXN + 1];// danh sach canh ke
vector<int> w(MAXN + 1);//trong so
long long dp[MAXN + 1][2];//dp[x][0]: tong trong so lon nhat khi khong chon x, dp[x][1]: tong trong so lon nhat khi chon x
vector<bool> visited(MAXN + 1);

/*
1.Xay dung cay tu dau vao
2. Duyet cay bang DFS tu goc(bat ki goc nao: root)
3. Ap dung quy hoach dong voi cong thuc: 
dp[v][0] = Tong xich ma(max(dp[neighbor][0], dp[neighbor][1])) => dp[v][0] += max(dp[neighbor][0], dp[neighbor][1])
dp[v][1] = w[v] + Tong xich ma(dp[neighbor][0]) => dp[v][1] += dp[neighbor][0]
4. Ket qua la max(dp[root][0], dp[root][1])
*/

void input(){
    cin >> n;
    int x, y;
    for(int i = 1; i <= n; i++){
        cin >> x;
        dp[i][1] = x;
        w[i] = x; 
        visited[i] = false;
    }

    for(int i = 1; i < n; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void dynamic_programing(int i){
    //Danh dau da den tham
    visited[i] = true;

    //Duyet cac dinh ke
    for(int neighbor : adj[i]){
        if(visited[neighbor] == false){
            dynamic_programing(neighbor);

            dp[i][0] += max(dp[neighbor][0], dp[neighbor][1]);
            dp[i][1] += dp[neighbor][0];
        }
    }
}

int main(){
    
    input();
    dynamic_programing(1);
    cout << max(dp[1][0], dp[1][1]) << endl;

    return 0;
}