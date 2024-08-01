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
    void print_stack(string note, stack<TreeNode *> s, bool enable) {
        if (enable == true) {
            cout << note;
            while (s.size() > 0) {
                cout << s.top()->val << ", ";
                s.pop();
            }
            cout << endl;            
        }
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            // cout << "root == nullptr false" << endl;
            return false;
        }
        bool debug_print_enable = false;
        stack<TreeNode *> s;
        s.push(root);
        int path_sum = root->val;
        // int stopper = 0;
        while (s.size() > 0) {
            // stopper++;
            // if (stopper > 20) {
            //     break;
            // }
            // cout << "stopper=" << stopper << ", ";
            // cout << "s.size()=" << s.size() << ": ";
            // print_stack("while begin: ", s, debug_print_enable);
            if (s.top()->left != nullptr) {
                s.push(s.top()->left);
                path_sum = path_sum + s.top()->val;
                // cout << "Go left, path_sum=" << path_sum << endl;
            } else if (s.top()->right != nullptr) {
                s.push(s.top()->right);
                path_sum = path_sum + s.top()->val;
                // cout << "Go right, path_sum=" << path_sum << endl;
            } else {
                if (path_sum == targetSum) {
                    // cout << "True" << endl;
                    return true;
                } else {
                    auto i = s.top();
                    path_sum = path_sum - s.top()->val;
                    cout << "Pop=" << i->val << ", path_sum=" << path_sum << endl;
                    s.pop();
                    if (s.size() == 0) {
                        // cout << "first pop false" << endl;
                        return false;
                    }

                    // print_stack("else-else: ", s, debug_print_enable);
                    // Continue popping from right child
                    while (   (s.top()->right == i)
                           || (s.top()->left == i && s.top()->right == nullptr) ) { 
                        i = s.top();
                        path_sum = path_sum - s.top()->val;
                        cout << "Pop=" << i->val << ", path_sum=" << path_sum << endl;
                        s.pop();
                        if (s.size() == 0) {
                            // cout << "while pop false" << endl;
                            return false;
                        }
                    }
                    if (s.top()->right != nullptr) {
                        s.push(s.top()->right);
                        path_sum = path_sum + s.top()->val;
                    }
                }
            }
            // print_stack("while end: ", s, debug_print_enable);
        }
        // cout << "end of program false" << endl;
        return false;
    }
};