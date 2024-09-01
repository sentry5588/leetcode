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
	// Learned from
	// https://leetcode.com/problems/binary-tree-maximum-path-sum/solutions/603423/python-recursion-stack-thinking-process-diagram/?envType=study-plan-v2&envId=top-interview-150
    int max_path;

    int maxPathSum(TreeNode* root) {
        max_path = root->val;
        max_gain(root);
        return max_path;
    }

    int max_gain(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int left_gain = 0, right_gain = 0;
        left_gain = max(max_gain(root->left), 0);
        right_gain = max(max_gain(root->right), 0);

        max_path = max(max_path, root->val + left_gain + right_gain);
        return root->val + max(left_gain, right_gain);
    }
};