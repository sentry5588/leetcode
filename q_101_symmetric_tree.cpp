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
    bool isSymmetric(TreeNode* root) {
        // Iterattive ===============================================================
        if (root == nullptr) {
            return true;
        }

        stack<TreeNode*> s_left, s_right;
        auto i_left = root, i_right = root;

        while (s_left.size() > 0 || s_right.size() > 0 || i_left != nullptr || i_right != nullptr) {
            if (s_left.size() != s_right.size()) {
                // cout << "stack size diff" << endl;
                return false;
            }
            if (    (i_left == nullptr && i_right != nullptr)
                 || (i_left != nullptr && i_right == nullptr) ) {
                // cout << "current node null mismatch" << endl;
                return false;
            }
            if (i_left != nullptr) {
                s_left.push(i_left);
                s_right.push(i_right);
                i_left = i_left->left;
                i_right = i_right->right;
            } else {
                i_left = s_left.top();
                i_right = s_right.top();
                if (i_left->val != i_right->val) {
                    return false;
                }
                // cout << i_left->val << ",";
                s_left.pop();
                s_right.pop();
                i_left = i_left->right;
                i_right = i_right->left;
            }
        }
        return true;
    }
};