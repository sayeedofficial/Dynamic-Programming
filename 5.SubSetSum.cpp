#include <bits/stdc++.h>
using namespace std;

bool solve(int *arr, int n, int target_sum) {
    if (n == 0)
        return false;
    if (target_sum == 0)
        return true;

    if (arr[n - 1] > target_sum) {
        return solve(arr, n - 1, target_sum);
    }
    return solve(arr, n, target_sum - arr[n - 1]) || solve(arr, n - 1, target_sum);
}

int memoArray[100][100];

int topDown(int *arr, int n, int target_sum) {
    if (memoArray[n - 1][target_sum] == -1) {
        if (n == 0)
            return 0;
        if (target_sum == 0)
            return 1;
        if (arr[n - 1] > target_sum) {
            memoArray[n - 1][target_sum] = topDown(arr, n - 1, target_sum);
        } else {
            memoArray[n - 1][target_sum] = topDown(arr, n, target_sum - arr[n - 1]) || topDown(arr, n - 1, target_sum);
        }
    }
    return memoArray[n - 1][target_sum];
}

int32_t main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target_sum;
    cin >> target_sum;

    cout << solve(arr, n, target_sum) << endl;
    memset(memoArray, -1, sizeof(memoArray));
    cout << topDown(arr, n, target_sum);
}
