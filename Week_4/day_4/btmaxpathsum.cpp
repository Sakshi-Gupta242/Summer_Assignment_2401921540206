#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int maxSum = INT_MIN;

    int solve(TreeNode* root) {

        if (root == nullptr)
            return 0;

        int left = max(0, solve(root->left));
        int right = max(0, solve(root->right));

        maxSum = max(maxSum, left + right + root->val);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {

        solve(root);

        return maxSum;
    }
};

int main() {

    // Tree:
    //       -10
    //       /  \
    //      9   20
    //         /  \
    //        15   7

    TreeNode* root = new TreeNode(-10);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    cout << "Maximum Path Sum: "
         << obj.maxPathSum(root);

    return 0;
}