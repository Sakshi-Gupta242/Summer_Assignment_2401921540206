#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        // Traverse all bars including one extra iteration
        for (int i = 0; i <= n; i++) {

            // Process bars while current bar is smaller
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {

                int height = heights[st.top()];
                st.pop();

                int width;

                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};

int main() {
    Solution obj;

    // Example 1
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << "Largest Rectangle Area = "
         << obj.largestRectangleArea(heights) << endl;

    return 0;
}