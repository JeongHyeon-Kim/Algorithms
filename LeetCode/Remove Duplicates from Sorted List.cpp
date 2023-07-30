// problem source: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// discussion reference: https://leetcode.com/problems/remove-duplicates-from-sorted-list/solutions/3257316/c-python-c-java-easiest-solution-o-n-time/

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* it = head;
        while (it) {
            // cout << it->val << " ";
            if (it->next) {
                ListNode* next_check = it->next;
                if (it->val == next_check->val) {
                    // cout << it->val << " ";
                    // cout << it->next->val << " ";
                    it->next = it->next->next;
                    continue;
                }
            }
            it = it->next;    
        }
        return head; 
    }
};

// Wrong with [1,1,1]
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* it = head;
        while (it) {
            // cout << it->val << " ";
            if (it->next) {
                ListNode* next_check = it->next;
                if (it->val == next_check->val) {
                    // cout << it->val << " ";
                    // cout << it->next->val << " ";
                    it->next = it->next->next;
                }
            }
            it = it->next;
        }
        // cout << endl;
        return head; 
    }
};