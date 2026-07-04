#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

// Function to find next greater elements
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

    stack<int> st;
    unordered_map<int, int> mp;

    // Process nums2
    for (int num : nums2) {

        while (!st.empty() && st.top() < num) {
            mp[st.top()] = num;
            st.pop();
        }

        st.push(num);
    }

    // Remaining elements have no greater element
    while (!st.empty()) {
        mp[st.top()] = -1;
        st.pop();
    }

    vector<int> ans;

    for (int num : nums1) {
        ans.push_back(mp[num]);
    }

    return ans;
}

int main() {

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements: ";

    for (int num : result) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}