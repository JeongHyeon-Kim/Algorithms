// problem source: https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto it = head;
        if (k == 1)
            return head;
        while (it != nullptr) {
            cout << it->val << " ";
            it = it->next;
        }
        cout << endl;
        cout << k << endl;
        return head;
    }
};
