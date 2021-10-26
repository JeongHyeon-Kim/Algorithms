// problem source: https://leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
        auto it = head;
        auto it2 = head;
        int node_count = 0;

        while (it != nullptr) {
            it = it -> next;
            node_count++;
        }

        if (node_count == 0 || node_count == 1)
            return head;

        while (it2 != nullptr && it2->next != nullptr) {
            int temp = it2->val;
            it2->val = it2->next->val;
            it2->next->val = temp;
            it2 = it2->next->next;
        }

        return head;
    }
};
