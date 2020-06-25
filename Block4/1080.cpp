#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>

using namespace std;

int color[100];
vector<int> graph[100];

bool bfs(int x) {
    queue<int> q;
    q.push(x);
    color[x] = 0;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            if (color[next] == -1) {
                color[next] = !color[now];
                q.push(next);
            } else if (color[next] == color[now])
                return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a;
        while (cin >> a && a) {
            graph[i].push_back(a);
            graph[a].push_back(i);
        }
    }

    memset(color, -1, sizeof(color));
    for (int i = 1; i <= N; i++) {
        if (color[i] == -1) {
            if (!bfs(i)) {
                cout << -1;
                return 0;
            }
        }
    }
    for (int i = 1; i <= N; i++)
        cout << color[i];
}
