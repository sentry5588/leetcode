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

        int h = 0;
        deque<TreeNode *> queue;
        queue.push_back(root);
        auto i_left = root, i_right = root;
        auto i = queue.front();

        // Breath first traverse using a queue
        // Approach: Use 2 pointers
        // Record the beginning and ending of each row
        while (queue.size() > 0) {
            i = queue.front();

            // Height related, added on top of traverse  ===================================
            if (i == i_left) {
                i_right = queue.back(); // update i_right
            }
            // -----------------------------------------------------------------------------

            queue.pop_front();
            // for (auto q:queue) cout <<q->val<<","; cout<<endl;
            if (i->left != nullptr) {
                queue.push_back(i->left);
            }
            if (i->right != nullptr) {
                queue.push_back(i->right);
            }

            // Height related, added on top of traverse  ===================================
            if (i == i_right) {
                h++; // Only increament h when a new i_left is seen
                i_left = queue.front(); // update i_left
            }
            // -----------------------------------------------------------------------------

        }

        return h;
        
    }
};