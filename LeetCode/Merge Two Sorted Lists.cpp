// problem source: https://leetcode.com/problems/merge-two-sorted-lists/
// discussion reference: https://leetcode.com/problems/merge-two-sorted-lists/discuss/1527745/C++-or-Faster-than-96

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
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         ListNode* result = new ListNode();
         ListNode* saved_front = result;

         while (l1 != nullptr && l2 != nullptr) {
             if (l1->val < l2->val) {
                 result->next = l1;
                 l1 = l1->next;
             } else { // l1->val >= l2->val
                 result->next = l2;
                 l2 = l2->next;
             }
             result = result->next;
         }

         while (l1 != nullptr) { // when remain l1 elements
             result->next = l1;
             result = result->next;
             l1 = l1->next;
         }

         while (l2 != nullptr) { // when remain l2 elements
             result->next = l2;
             result = result->next;
             l2 = l2->next;
         }

         return saved_front->next;
     }
 };
