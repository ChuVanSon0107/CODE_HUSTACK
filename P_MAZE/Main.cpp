#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int n, m, r, c;

int path[1000][1000];
int maze[1000][1000];

void nhap(){
    cin >> n >> m >> r >> c;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> maze[i][j];
            path[i][j] = 0;
        }
    }
}

void findPath(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    maze[i][j] = 1;
    path[i][j] = 1;
    pair<int, int> a;
    while(q.empty() == false){
        a = q.front();
        q.pop();

        for(int k = 0; k < 4; k++){
            int x = a.first + dx[k];
            int y = a.second + dy[k];

            if(0 <= x && x < n && 0 <= y && y < m && maze[x][y] == 0){
                maze[x][y] = 1;
                path[x][y] = path[a.first][a.second] + 1;
                q.push({x, y});
            }
        }
    }
}

int main(){
    nhap();
    findPath(r - 1, c - 1);
    int distance = INT_MAX;
    for(int i = 0; i < n; i++){
        if(path[i][0] != 0){
            distance = min(distance, path[i][0]);
        }
        if(path[i][m - 1] != 0){
            distance = min(distance, path[i][m - 1]);
        }
    }

    for(int i = 0; i < m; i++){
        if(path[0][i] != 0){
            distance = min(distance, path[0][i]);
        }
        if(path[n - 1][i] != 0){
            distance = min(distance, path[n - 1][i]);
        }
    }
    if(distance == INT_MAX){
        cout << -1;
    }
    else cout << distance;

    return 0;
}