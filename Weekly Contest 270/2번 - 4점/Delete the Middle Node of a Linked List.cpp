// problem source: https://leetcode.com/contest/weekly-contest-270/problems/delete-the-middle-node-of-a-linked-list/
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* it = head;
        ListNode* it2 = head;
        int node_count = 1;
        while (it->next != nullptr) {
            node_count++;
            it = it->next;
        }
        if (node_count == 1) {
            return nullptr;
        }
        if (node_count == 2) {
            head->next = nullptr;
            return head;
        }
        int middle_index = node_count / 2;
        while (it2->next != nullptr && it2->next->next != nullptr) {
            middle_index--;
            if (middle_index == 0)
                it2->next = it2->next->next;
            it2 = it2->next;
        }
        return head;
    }
};
