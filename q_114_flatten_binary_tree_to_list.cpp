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
    void flatten(TreeNode* root) {
        if (root != nullptr) {

            stack<TreeNode *> s;
            s.push(root);
            auto prev = root;
            while (s.size() > 0) {
                auto i = s.top();
                // ================================================================
                // Problem specific lines in addition to pre-order traversal
                if (i != root) {
                    prev->left = nullptr;
                    prev->right = i;
                    prev = i;
                }
                // ================================================================
                // cout << i->val << ",";
                s.pop();
                if (i->right != nullptr) {
                    s.push(i->right);
                }
                if (i->left != nullptr) {
                    s.push(i->left);
                }
            }
        }
    }
};