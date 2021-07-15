// problem source: https://leetcode.com/problems/merge-k-sorted-lists/
// discussion reference: https://leetcode.com/problems/merge-k-sorted-lists/discuss/1336960/Priority-queue-oror-C%2B%2B
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *result = NULL;
        ListNode *temp;
        priority_queue<pair<int, ListNode*>> lists_queue;
        int lists_size = lists.size();
        for(int i = 0; i < lists_size; i++) {
            if(lists[i] != NULL)
                lists_queue.push({-lists[i]->val, lists[i]});
        }
        while(!lists_queue.empty()) {
            auto top_element = lists_queue.top();
            lists_queue.pop();
            if(result == NULL) {
                ListNode* temp1 = new ListNode(-top_element.first);
                result = temp1;
                temp = temp1;
            } else {
                ListNode* temp1 = new ListNode(-top_element.first);
                temp->next = temp1;
                temp = temp1;
            }
            if(top_element.second->next != NULL){
                top_element.second = top_element.second->next;
                lists_queue.push({-top_element.second->val, top_element.second});
            }

        }
        return result;
    }
};
