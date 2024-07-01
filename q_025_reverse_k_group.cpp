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
    // 1. create a method to reverse the list, given head and tail
    ListNode* reverse_section(ListNode* const begin, ListNode* const end_next) {
        auto new_end = begin;
        auto new_begin = begin;
        ListNode* prev = nullptr;
        while (new_begin != end_next) {
            auto next = new_begin->next;
            new_begin->next = prev;
            prev = new_begin;
            new_begin = next;
        }
        new_end->next = end_next;

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) {
            return head;
        }

        ListNode sentinel;
        sentinel.next = head;
        auto prev_section = &sentinel, prev = head;
        auto curr = head->next;
        int count = 1;
        auto begin_section = head;
        while (curr != nullptr) {
            auto nxt = curr->next;
            if (count % k == k - 1) {
                prev_section->next = reverse_section(begin_section, curr->next);
                prev_section = begin_section;
                begin_section = prev_section->next;
            }
            prev = curr;
            curr = nxt;
            count++;
        }

        return sentinel.next;
    }
};