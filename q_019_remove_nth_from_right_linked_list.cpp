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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Thought: This feel like the solution of hare and turtle to detect rings in linked list
        ListNode* sentinel = new ListNode();
        sentinel->next = head;
        auto fast = sentinel;
        auto slow = sentinel;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        // cout << "i=" << i << endl;
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* to_delete = slow->next;
        slow->next = slow->next->next;
        delete to_delete; // Delete to free resource

        return sentinel->next;
    }
};