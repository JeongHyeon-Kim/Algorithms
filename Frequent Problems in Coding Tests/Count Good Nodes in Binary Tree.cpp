// problem source: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
// discussion reference: https://leetcode.com/problems/count-good-nodes-in-binary-tree/discuss/1493911/C++-oror-Simple-DFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int recursive_method(TreeNode* node, int max_value) {
        if (node == nullptr)
            return 0;
        int good_node_count = 0;
        if (node->val >= max_value) { // condition for good node (including root node)
            good_node_count++;
            max_value = node->val;
        }
        return good_node_count + recursive_method(node->right, max_value) + recursive_method(node->left, max_value);
    }

    int goodNodes(TreeNode* root) {
        return recursive_method(root, root->val);
    }

    // Traversal Example
    // int recursive_method(TreeNode* node, int& value) {
    //     TreeNode* left = node->left;
    //     TreeNode* right = node->right;
    //     cout << value << endl;
    //     if (left != nullptr) {
    //         recursive_method(left, left->val);
    //     }
    //     if (right != nullptr) {
    //         recursive_method(right, right->val);
    //     }
    //     return 0;
    // }
    //
    // int goodNodes(TreeNode* root) {
    //     return recursive_method(root, root->val);
    // }
};
