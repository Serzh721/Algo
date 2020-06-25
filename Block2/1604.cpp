#include <iostream>

using namespace std;

void swap(int nums[], int i, int j) {
    int q = nums[i];
    nums[i] = nums[j];
    nums[j] = q;
}

void qSort(int nums[], int p[], int l, int r) {
    int i = l;
    int j = r;
    long m = nums[(l + r) / 2];

    while (i <= j) {
        while (nums[i] < m) i++;
        while (nums[j] > m) j--;
        if (i > j) break;
        swap(nums, i, j);
        swap(p, i, j);
        i++;
        j--;
    }
    if (l < j) qSort(nums, p, l, j);
    if (i < r) qSort(nums, p, i, r);
}

int main() {
    int n;
    cin >> n;
    int nums[10001];
    int p[10001];
    int ans[10001];
    int sum = 0, k = 0;
    int l, r;
    int min, max;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
        p[i] = i + 1;
    }

    qSort(nums, p, 0, n - 1);
    l = 0, r = n - 1;

    while (k < sum) {
        max = 0;
        min = 10000;
        ans[k] = p[r];
        --nums[r];
        k++;
        ans[k] = p[l];
        --nums[l];
        k++;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                if (nums[i] < min) {
                    min = nums[i];
                    l = i;
                }
                if (nums[i] > max && i != l) {
                    max = nums[i];
                    r = i;
                }
            }
        }
    }
    for (int i = 0; i < sum; i++) { std::cout << ans[i] << " " << std::endl; }
}
