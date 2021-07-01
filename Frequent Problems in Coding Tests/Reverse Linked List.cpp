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
        if (head == nullptr)
            return head;
        else {
            ListNode* result = new ListNode();
            list<int> test;
            stack<int> reverse;
            while (head != nullptr) {
                reverse.push(head->val);
                head = head->next;
            }
            if (!reverse.empty()) {
                result->val = reverse.top();
                reverse.pop();
            }
            ListNode* pointing = result;
            while (!reverse.empty()) {
                ListNode* newNode = new ListNode(reverse.top());
                reverse.pop();
                pointing->next = newNode;
                pointing = pointing->next;
            }
            return result;
        }
    }
};
