/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        auto i = head;
        Node* new_list_head = nullptr;
        auto j = new_list_head;
        unordered_map<Node *, Node *> old_to_new;
        while (i != nullptr) {
            auto p = new Node(i->val);
            old_to_new.insert(pair<Node *, Node *>(i, p));
            // cout << "p->val=" << p->val << endl;
            if (new_list_head == nullptr) {
                new_list_head = p;
                j = new_list_head;
            } else {
                j->next = p;
                j = j->next;
            }
            i = i->next;
        }

        // step 2, go thru original list and create the link
        i = head;
        j = new_list_head;
        while (i != nullptr) {
            j->random = old_to_new[i->random];
            i = i->next;
            j = j->next;
        }
        
        return new_list_head;
    }
};