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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        size_t h = 1;
        stack<TreeNode *> stack;
        auto i = root;
        stack.push(i);
        while (stack.size() > 0) {
            i = stack.top();
            stack.pop();

            if (i->right != nullptr) {
                stack.push(i->right);
            }
            if (i->left != nullptr) {
                stack.push(i->left);
            }
            h = max(h, stack.size());
            // cout << "stack.size()=" << stack.size()
            //      << ", i->val=" << i->val
            //      << endl;
        }
        return (int)h;
    }
};
