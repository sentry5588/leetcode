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
private:
    bool isSameNode(TreeNode* p, TreeNode* q) {
        if ( (p == nullptr && q != nullptr) || (p != nullptr && q == nullptr) ) {
            return false;
        } else if (p == nullptr && q == nullptr) {
            return true;
        }

        if (   (p->val != q->val)
            || (p->left != nullptr && q->left == nullptr)
            || (p->left == nullptr && q->left != nullptr)
            || (p->right != nullptr && q->right == nullptr)
            || (p->right == nullptr && q->right != nullptr) ) {
            return false;
        } 
        return true;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ( (p == nullptr && q != nullptr) || (p != nullptr && q == nullptr) ) {
            return false;
        } else if (p == nullptr && q == nullptr) {
            return true;
        }

        stack<TreeNode*> stack_p, stack_q;
        stack_p.push(p);
        stack_q.push(q);
        while (stack_p.size() > 0 || stack_p.size() > 0) {
            if (stack_p.size() != stack_p.size()) {
                return false;
            }
            auto ip = stack_p.top();
            auto iq = stack_q.top();
            stack_p.pop();
            stack_q.pop();
            if ( isSameNode(ip, iq) == false) {
                return false;
            }
            if (ip->right) {
                stack_p.push(ip->right);
                stack_q.push(iq->right);
            }
            if (ip->left) {
                stack_p.push(ip->left);
                stack_q.push(iq->left);
            }
        }
        return true;
    }
};

// recursive solution below
// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if ( (p == nullptr && q != nullptr) || (p != nullptr && q == nullptr) ) {
//             return false;
//         } else if (p != nullptr && q != nullptr) {
//             if (p->val == q->val) {
//                 if (isSameTree(p->left, q->left) == false) {
//                     return false;
//                 }
//                 if (isSameTree(p->right, q->right) == false) {
//                     return false;
//                 }
//             } else {
//                 return false;
//             }
//         }
//         return true;
//     }
// };