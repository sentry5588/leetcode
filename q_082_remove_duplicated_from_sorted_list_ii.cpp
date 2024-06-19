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
    ListNode* deleteDuplicates(ListNode* head) {
        auto sentinel = new ListNode();
        sentinel->next = head;
        auto slow = sentinel, fast = sentinel;
        int length = 0;
        while (fast->next != nullptr) {
            if (slow->next->val != fast->next->val) {
                if (length == 1) { // Not a duplicate, slow to catch up
                    slow = slow->next;
                } else { // duplicates, remove from slow->next to fast
                    auto to_be_deleted = slow->next;
                    slow->next = fast->next;
                    fast = slow;
                    while (to_be_deleted != slow->next) {
                        auto node_to_be_deleted = to_be_deleted;
                        to_be_deleted = to_be_deleted->next;
                        delete node_to_be_deleted;
                    }
                }
                length = 0;
            } else {
                fast = fast->next;
                length++;
            }
        }
        if (length > 1) {
            slow->next = nullptr;
        }
        return sentinel->next;
    }
};