#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int n;
    cin >> n;
    int sum = 0;
    int nums[n];
    int arr[n];
    double max = -1;

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        sum += nums[i];
    }

    double ideal = double(sum) / 2;
    int k = pow(2, n) - 1;

    for (int i = 0; i <= k; ++i) {

        int counter = 1;
        int mid = i;

        while (mid > 0) {
            if (mid % 2 == 0) {
                arr[n - counter] = 0;
            } else {
                arr[n - counter] = 1;
            }
            mid = mid / 2;
            counter++;
        }

        double s = 0;
        for (int j = 0; j < n; ++j) {
            if (arr[j] == 1) {
                s += nums[j];
            }
        }
        if (abs(s - ideal) < max || max == -1) {
            max = abs(s - ideal);
        }

    }
    std::cout << max * 2 << std::endl;

}
