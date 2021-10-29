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
        vector<int> middle_solution;

        if (k == 1)
            return head;

        while (it != nullptr) {
            middle_solution.push_back(it->val);
            it = it->next;
        }

        int node_count = middle_solution.size();
        int iteration = node_count / k;

        for (int i = 0; i < iteration; i++) {
            for (int j = 0; j < (k / 2); j++) {
                int temp = middle_solution[i * k + j]; // i * k is jumping next group
                middle_solution[i * k + j] = middle_solution[(k - 1) + (i * k) - j]; // (k - 1) is in group element from backward
                middle_solution[(k - 1) + (i * k) - j] = temp; // j is backward index
            }
        }

        ListNode* result = new ListNode(middle_solution[0]);
        auto it2 = result;
        for (int i = 1; i < node_count; i++) {
            ListNode* newNode = new ListNode(middle_solution[i]);
            it2->next = newNode;
            it2 = it2->next;
        }

        return result;
    }
};
