#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int maxi = 0;

    while (left < right) {
        int width = right - left;
        int h = min(height[left], height[right]);

        maxi = max(maxi, width * h);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxi;
}

int main() {
    int n;
    cin >> n;

    vector<int> height(n);

    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << maxArea(height);

    return 0;
}