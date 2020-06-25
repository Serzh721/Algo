#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long x[1000001];
    long long y[1000001];
    long long Xs = 0, Ys = 0;
    long long k, ans;

    for (int i = 0; i < n; i++) { cin >> x[i] >> y[i]; }

    sort(x, x + n);
    sort(y, y + n);

    for (int i = 1; i < n; i++) {
        k = i * (n - i);
        Xs += (x[i] - x[i - 1]) * k * 2;
        Ys += (y[i] - y[i - 1]) * k * 2;
    }
    ans = (Xs + Ys) / (n * (n - 1));

    std::cout << ans << std::endl;
}
