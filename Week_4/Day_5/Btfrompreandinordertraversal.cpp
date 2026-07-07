#include <iostream>
#include <vector>
#include <unordered_map>
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
    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    int inStart, int inEnd) {

        if (inStart > inEnd)
            return nullptr;

        // Create root node
        int rootValue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootValue);

        // Find root in inorder
        int pos = mp[rootValue];

        // Build left subtree
        root->left = solve(preorder, inorder, inStart, pos - 1);

        // Build right subtree
        root->right = solve(preorder, inorder, pos + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store inorder index in map
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return solve(preorder, inorder, 0, inorder.size() - 1);
    }
};

// Inorder Traversal
void inorderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Preorder Traversal
void preorderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;

    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution obj;

    TreeNode* root = obj.buildTree(preorder, inorder);

    cout << "Preorder Traversal: ";
    preorderTraversal(root);

    cout << endl;

    cout << "Inorder Traversal: ";
    inorderTraversal(root);

    return 0;
}