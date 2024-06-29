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
    ListNode* partition(ListNode* head, int x) {
        // 1. Find the first elem in the 2nd half
        
        // Using ListNode *sentinel = new ListNode() causes memory leaks
        ListNode sentinel_node;
        auto sentinel = &sentinel_node;

        sentinel->next = head;
        auto i = sentinel, j = sentinel;
        while (i->next != nullptr) {
            if (i->next->val < x) {
                i = i->next;
            } else {
                break;
            }
        }
        j = i;

        // 2. Move smaller ones ahead of i
        while (j->next != nullptr) {
            if (j->next->val >= x) {
                j = j->next;
            } else {
                auto small = j->next;
                j->next = j->next->next;
                small->next = i->next;
                i->next = small;
                i = small; // Move i ahead so that order is perserved
            }
        }

        return sentinel->next;
    }
};