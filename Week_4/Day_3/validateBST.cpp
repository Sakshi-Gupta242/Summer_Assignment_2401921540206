#include <iostream>
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
    bool check(TreeNode* root, long long minVal, long long maxVal) {

        if (root == nullptr)
            return true;

        if (root->val <= minVal || root->val >= maxVal)
            return false;

        return check(root->left, minVal, root->val) &&
               check(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {

    // Create BST
    //        5
    //       / \
    //      3   7
    //     / \   \
    //    2   4   8

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(8);

    Solution obj;

    if (obj.isValidBST(root))
        cout << "Valid BST";
    else
        cout << "Not a Valid BST";

    return 0;
}