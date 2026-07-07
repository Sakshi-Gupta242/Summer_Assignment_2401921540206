#include <iostream>
#include <queue>
#include <sstream>
#include <string>
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

class Codec {
public:

    // Serialize Tree
    string serialize(TreeNode* root) {

        if (root == nullptr)
            return "";

        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                ans += "N,";
            } else {
                ans += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }

        return ans;
    }

    // Deserialize Tree
    TreeNode* deserialize(string data) {

        if (data.empty())
            return nullptr;

        stringstream ss(data);
        string str;

        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            // Left Child
            if (!getline(ss, str, ','))
                break;

            if (str != "N") {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            // Right Child
            if (!getline(ss, str, ','))
                break;

            if (str != "N") {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }

        return root;
    }
};

// Inorder Traversal (Verification)
void inorder(TreeNode* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    // Create Tree
    //       1
    //      / \
    //     2   3
    //        / \
    //       4   5

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec obj;

    // Serialize
    string data = obj.serialize(root);

    cout << "Serialized Tree:\n";
    cout << data << endl;

    // Deserialize
    TreeNode* newRoot = obj.deserialize(data);

    cout << "\nInorder Traversal After Deserialization:\n";
    inorder(newRoot);

    return 0;
}