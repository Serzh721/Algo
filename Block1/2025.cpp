#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    int n;
    int k;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        cin >> k;
        int nums[n];
        int w = 0;
        for (int j = 0; j < n; ++j) {
            w++;
            nums[j] = w;
            if (w == k) {
                w = 0;
            }
        }

        int counter = 0;

        for (int l = 0; l < n - 1; l++) {
            for (int q = l + 1; q < n; q++) {
                if (nums[l] != nums[q]) {
                    counter++;
                }
            }
        }
        std::cout << counter << std::endl;

    }
    return 0;
}
