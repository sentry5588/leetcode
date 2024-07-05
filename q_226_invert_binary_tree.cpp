/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        // =================================================
        // Recursive solution
        // if (root == nullptr) {
        //     return root;
        // }

        // auto temp_node_p = root->left;
        // root->left = root->right;
        // root->right = temp_node_p;

        // invertTree(root->left);
        // invertTree(root->right);
        // return root;


        // =================================================
        // Iterative solution
        if (root == nullptr) {
            return root;
        }

        stack<TreeNode*> s;
        s.push(root);
        while (s.size() > 0) {
            auto i = s.top();
            s.pop();
            if (i->left) {
                s.push(i->left);
            }
            if (i->right) {
                s.push(i->right);
            }
            auto temp_node_p = i->left;
            i->left = i->right;
            i->right = temp_node_p;
        }
        return root;
    }
};