// problem source: https://www.hackerrank.com/challenges/tree-level-order-traversal/problem
// discussion reference: https://www.hackerrank.com/challenges/tree-level-order-traversal/forum/comments/172493
// Abort Called, Wrong Answer 보완 필요
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/

    void levelOrder(Node * root) {
        // if (!root)
        //     return;
        // else {
        //     cout << root->data << " ";
        //     levelOrder(root->left);
        //     levelOrder(root->right);
        // }
        queue<Node*> q;
        Node* temp = root;

        while (temp) {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            temp = q.front();
            q.pop();
        }
    }

}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

	myTree.levelOrder(root);
    return 0;
}
