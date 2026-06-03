#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);

    int left = 0, right = n - 1;
    int idx = n - 1;

    while (left <= right) {
        if (abs(nums[left]) > abs(nums[right])) {
            ans[idx] = nums[left] * nums[left];
            left++;
        } else {
            ans[idx] = nums[right] * nums[right];
            right--;
        }
        idx--;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> ans = sortedSquares(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}