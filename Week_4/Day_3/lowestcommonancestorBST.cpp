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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == nullptr)
            return nullptr;

        // Both nodes are in the left subtree
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);

        // Both nodes are in the right subtree
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);

        // Current node is the Lowest Common Ancestor
        return root;
    }
};

int main() {

    // BST
    //          6
    //        /   \
    //       2     8
    //      / \   / \
    //     0   4 7   9
    //        / \
    //       3   5

    TreeNode* root = new TreeNode(6);

    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);

    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    // Example: Find LCA of 2 and 8
    TreeNode* p = root->left;   // Node 2
    TreeNode* q = root->right;  // Node 8

    Solution obj;

    TreeNode* ans = obj.lowestCommonAncestor(root, p, q);

    if (ans != nullptr)
        cout << "Lowest Common Ancestor: " << ans->val << endl;
    else
        cout << "No Common Ancestor Found";

    return 0;
}