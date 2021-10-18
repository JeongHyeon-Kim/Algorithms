// problem source: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
        int list_size = 0;
        int forward_order = 0;
        ListNode* it = head;
        ListNode* it2 = head;

        while (it != nullptr) { // get list size
            list_size++;
            it = it->next;
        }

        if ( ( list_size == 1 && n == 1 ) || ( ((list_size - 1) - (n - 1) - 1) == -1 ) ) {
            head = head->next;
            return head;
        }

        while (it2 != nullptr) {
            if (forward_order == ( (list_size - 1) - (n - 1) - 1) ) { // get before deleting position
                ListNode* deleting_node = it2->next;
                it2->next = it2->next->next;
                delete(deleting_node);
                break;
            }
            forward_order++;
            it2 = it2->next;
        }

        return head;
    }
};
