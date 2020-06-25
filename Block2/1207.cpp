#include <iostream>
#include <cmath>

#define PI 3.14159265359

using namespace std;

void swap(long nums[], int i, int j) {
    long q = nums[i];
    nums[i] = nums[j];
    nums[j] = q;
}

void swap2(double nums[], int i, int j) {
    double q = nums[i];
    nums[i] = nums[j];
    nums[j] = q;
}

void qSort(double nums[], long p[], long l, long r) {
    long i = l;
    long j = r;
    double m = nums[(l + r) / 2];

    while (i <= j) {
        while (nums[i] < m) i++;
        while (nums[j] > m) j--;
        if (i > j) break;
        swap2(nums, i, j);
        swap(p, i, j);
        i++;
        j--;
    }
    if (l < j) qSort(nums, p, l, j);
    if (i < r) qSort(nums, p, i, r);
}

int main() {
    long n;
    cin >> n;

    long x[n], y[n], p[n];
    double ang[n];
    long maxY = LONG_MIN, pos = 0;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        cin >> y[i];
        p[i] = i + 1;
        if (y[i] > maxY || (y[i] == maxY && x[i] < x[pos])) {
            maxY = y[i];
            pos = i;
        }
    }

    long q = x[0];
    x[0] = x[pos];
    x[pos] = q;

    q = y[0];
    y[0] = y[pos];
    y[pos] = q;

    q = p[0];
    p[0] = p[pos];
    p[pos] = q;

    for (int i = 1; i < n; i++) {
        if (x[i] == x[0]) {
            ang[i] = PI / 2;
        } else if (y[i] == y[0]) {
            ang[i] = 0;
        } else {
            ang[i] = atan((double) (y[0] - y[i]) / (double) (x[i] - x[0]));
        }
        if (ang[i] < 0) {
            ang[i] = ang[i] + PI;
        }
    }
    
    qSort(ang, p, 1, n - 1);

    std::cout << p[0] << " " << p[n / 2] << std::endl;
}
