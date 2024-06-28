/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }

        // 1. find the length
        ListNode* sentinel = new ListNode();
        sentinel->next = head;
        auto np = sentinel;
        int len = 0;
        while (np->next != nullptr) {
            np = np->next;
            len++;
        }
        auto tail = np;
        np->next = head; // loop back
        // cout << "Linked list length len = " << len << endl;

        // 2. find the num of rotate < length
        k = len - (k % len);
        // cout << "Actual rotate num k = " << k << endl;

        // 3. do the rotate
        while (k > 0) {
            // cout << "tail->val = " << tail->val << ", head->val = " << head->val << ", k=" << k << endl;
            tail = head;
            head = head->next;
            k--;
        }
        tail->next = nullptr;
        delete sentinel;
        return head;
        // 4. Space O(1), traverse twice, time O(n)
    }
};