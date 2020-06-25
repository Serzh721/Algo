#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n];
    int sum = 0;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        k += nums[i];
        if (k < 0) k = 0;
        if (k > sum) sum = k;
    }

    std::cout << sum << std::endl;
    return 0;
}
