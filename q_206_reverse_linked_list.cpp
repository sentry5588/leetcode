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
    ListNode* reverseList(ListNode* head) {
        ListNode* i_prev = nullptr;
        auto i = head;
        while (i != nullptr) {
            auto i_next = i->next;
            i->next = i_prev;
            i_prev = i;
            i = i_next;
        }
        return i_prev;
    }
};