/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }

        queue<Node *> q;
        Node *left_n = root;
        Node *right_n = root;
        q.push(root);
        while (q.size() > 0) {
            auto i = q.front();
            // cout << i->val << ",";
            q.pop();
            if (i == left_n) {
                right_n = q.back();
            }
            if (i->left != nullptr) {
                q.push(i->left);
            }
            if (i->right != nullptr) {
                q.push(i->right);
            }
            if (i == right_n) {
                left_n = q.front();
            } 
            // ================================================================
            // Problem specific lines in addition to Level Order Traversal
            else {
                i->next = q.front();
            }
            // ================================================================
        }

        return root;        
    }
};