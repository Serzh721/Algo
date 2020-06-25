#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> balls;
    int x[n + 1];
    int pos = 1;

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        balls.push(i);
        while (!balls.empty() && balls.top() == x[pos]) {
            balls.pop();
            pos++;
        }
    }
    if (balls.empty())
        cout << "Not a proof" << endl;
    else
        cout << "Cheater" << endl;

}
