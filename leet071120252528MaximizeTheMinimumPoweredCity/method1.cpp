#include<iostream>
using namespace std;

bool check(vector < long long > differenceArray, int r, int k, long long mid) {
    long long sum = 0;
    int n = differenceArray.size() - 1;
    for (int i = 0; i < n; i++) {
        sum += differenceArray[i];
        if (sum < mid) {
            long long add = mid - sum;
            if (k < add) {
                return false;
            }
            k -= add;
            int right = min(i + 2 * r + 1, n);
            differenceArray[right] -= add;
            sum += add;
        }
    }
    return true;
}
long long maxPower(vector < int > & stations, int r, int k) {
    vector < long long > differenceArray(stations.size() + 1, 0);
    long long start = 0;
    long long end = 0;
    int n = stations.size();
    for (int i = 0; i < stations.size(); i++) {
        end += stations[i];
        int left = max(0, i - r);
        int right = min(n, i + r + 1);
        differenceArray[left] += stations[i];
        differenceArray[right] -= stations[i];
    }
    end += k;
    long long ans = 0;
    while (start <= end) {
        long long mid = start + (end - start) / 2;
        if (check(differenceArray, r, k, mid)) {
            start = mid + 1;
            ans = mid;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}