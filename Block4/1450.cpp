#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[501], price[501];
int memo[501];
int S, F;

int solve(int pos) {
    if (pos == F) return 0;

    int &ret = memo[pos];
    if (ret == -1) {
        ret = -2;

        for (int i = graph[pos].size() - 1; i >= 0; i--) {
            int sum = solve(graph[pos][i]);

            if (sum != -2) {
                sum += price[pos][i];
                ret = max(ret, sum);
            }
        }
    }
    return ret;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back(B);
        price[A].push_back(C);
    }

    cin >> S >> F;
    memset(memo, -1, sizeof memo);

    int ret = solve(S);
    if (ret == -2)
        cout << "No solution";
    else
        cout << ret;
}
