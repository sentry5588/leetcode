/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        auto slow_pointer = head;
        auto fast_pointer = head->next;
        while (fast_pointer != NULL) {
            slow_pointer = slow_pointer->next;
            fast_pointer = fast_pointer->next;
            if (fast_pointer == NULL) {
                break;
            } else {
                fast_pointer = fast_pointer->next;
            }
            if (fast_pointer == slow_pointer) {
                return true;
            }
        }
        return false;
    }
};