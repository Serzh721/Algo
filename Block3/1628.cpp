#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
typedef pair<int, int> coordinate;

bool row_sort(coordinate a, coordinate b) {
    if (a.first != b.first)
        return a.first < b.first;
    else
        return a.second < b.second;
}

bool column_sort(coordinate a, coordinate b) {
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int main() {
    coordinate black[180000];
    set<coordinate> alone;

    int m, n, k;
    cin >> m >> n >> k;
    int ans = 0, x = 0, y = 0;

    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        black[i] = make_pair(x, y);
    }

    for (int i = 1; i <= n; i++) {
        black[k++] = make_pair(0, i);
        black[k++] = make_pair(m + 1, i);
    }
    for (int i = 1; i <= m; i++) {
        black[k++] = make_pair(i, 0);
        black[k++] = make_pair(i, n + 1);
    }

    sort(black, black + k, row_sort);
    for (int i = 0; i < k - 1; i++) {
        int interval = black[i + 1].second - black[i].second;
        if (black[i].first == black[i + 1].first && interval >= 2) {
            if (interval == 2)
                alone.insert(make_pair(black[i].first, black[i].second + 1));
            else
                ans++;
        }
    }

    sort(black, black + k, column_sort);
    for (int i = 0; i < k - 1; i++) {
        int interval = black[i + 1].first - black[i].first;
        if (black[i].second == black[i + 1].second && interval >= 2) {
            if (interval == 2) {
                if (alone.find(make_pair(black[i].first + 1, black[i].second)) != alone.end())
                    ans++;
            } else
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
