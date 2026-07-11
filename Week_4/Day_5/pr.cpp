#include <iostream>
using namespace std;

// Tree Node
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
    TreeNode* searchBST(TreeNode* root, int val) {

        if (root == nullptr || root->val == val)
            return root;

        if (val < root->val)
            return searchBST(root->left, val);

        return searchBST(root->right, val);
    }
};

int main() {

    // BST
    //       4
    //      / \
    //     2   7
    //    / \
    //   1   3

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 2;

    Solution obj;
    TreeNode* result = obj.searchBST(root, val);

    if (result == nullptr) {
        cout << "Value not found";
    } else {
        cout << "Node Found: " << result->val << endl;

        if (result->left)
            cout << "Left Child: " << result->left->val << endl;

        if (result->right)
            cout << "Right Child: " << result->right->val << endl;
    }

    return 0;