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
        ListNode* result = new ListNode();
        auto it1 = l1, it2 = l2, it3 = result;
        int sum = 0, remain = 0, carry = 0;
        while (it1 != nullptr || it2 != nullptr) {
            if (it1 != nullptr && it2 != nullptr) {
                sum = it1->val + it2->val + carry;
                remain = sum % 10;
                carry = sum / 10;
                it3->val = remain;
                if (it1->next != nullptr || it2->next != nullptr) {
                    ListNode* newNode = new ListNode();
                    it3->next = newNode;
                    it3 = it3->next;
                }
                it1 = it1->next;
                it2 = it2->next;
            } else if (it1 == nullptr && it2 != nullptr) {
                sum = it2->val + carry;
                remain = sum % 10;
                carry = sum / 10;
                it3->val = remain;
                if (it2->next != nullptr) {
                    ListNode* newNode = new ListNode();
                    it3->next = newNode;
                    it3 = it3->next;
                }
                it2 = it2->next;
            } else if (it1 != nullptr && it2 == nullptr) {
                sum = it1->val + carry;
                remain = sum % 10;
                carry = sum / 10;
                it3->val = remain;
                if (it1->next != nullptr) {
                    ListNode* newNode = new ListNode();
                    it3->next = newNode;
                    it3 = it3->next;
                }
                it1 = it1->next;
            } else {
                cout << "exception" << endl;
            }
        }
        if (it1 == nullptr && it2 == nullptr && carry != 0) {
            ListNode* newNode = new ListNode(carry);
            it3->next = newNode;
        }
        return result;
    }
};
