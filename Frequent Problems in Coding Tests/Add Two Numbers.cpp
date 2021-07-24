// problem source: https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto it1 = l1, it2 = l2;
        ListNode* result = new ListNode();
        while (it1 != nullptr) {
            cout << it1->val << " ";
            it1 = it1->next;
        }
        cout << endl;
        while (it2 != nullptr) {
            cout << it2->val << " ";
            it2 = it2->next;
        }
        return result;
    }
};
