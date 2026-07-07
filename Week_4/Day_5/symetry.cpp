#include <iostream>
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
    bool mirror(TreeNode* left, TreeNode* right) {

        if (left == nullptr && right == nullptr)
            return true;

        if (left == nullptr || right == nullptr)
            return false;

        if (left->val != right->val)
            return false;

        return mirror(left->left, right->right) &&
               mirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {

        if (root == nullptr)
            return true;

        return mirror(root->left, root->right);
    }
};

int main() {

    // Symmetric Tree
    //         1
    //       /   \
    //      2     2
    //     / \   / \
    //    3   4 4   3

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution obj;

    if (obj.isSymmetric(root))
        cout << "Tree is Symmetric";
    else
        cout << "Tree is Not Symmetric";

    return 0;
}