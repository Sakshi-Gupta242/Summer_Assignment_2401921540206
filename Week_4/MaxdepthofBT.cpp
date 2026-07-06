#include <iostream>
#include <algorithm>

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
    int maxDepth(TreeNode* root) {
        // Base case
        if (root == nullptr)
            return 0;

        // Recursively find depth of left and right subtree
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // Return maximum depth + 1 (current node)
        return 1 + max(leftDepth, rightDepth);
    }
};

int main() {
    // Creating the tree:
    //        3
    //       / \
    //      9  20
    //         / \
    //        15  7

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    cout << "Maximum Depth = " << obj.maxDepth(root) << endl;

    return 0;
}