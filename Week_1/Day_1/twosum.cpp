#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        if (mp.find(complement) != mp.end()) {
            cout << mp[complement] << " " << i << endl;
            return 0;
        }
        mp[nums[i]] = i;
    }
    cout << "No two sum solution" << endl;
    return 0;
}