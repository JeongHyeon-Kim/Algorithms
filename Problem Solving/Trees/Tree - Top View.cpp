// problem source: https://www.hackerrank.com/challenges/tree-top-view/problem
// discussion reference: https://www.hackerrank.com/challenges/tree-top-view/forum/comments/148307, https://www.hackerrank.com/challenges/tree-top-view/forum/comments/572408
#include<bits/stdc++.h>

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
    // // try1
    // bool left_end = false;
    // void topView(Node * root) {
    //     if (!left_end) {
    //         if (!root) {
    //             left_end = true;
    //             return;
    //         } else {
    //             topView(root->left);
    //             cout << root->data << " ";
    //         }
    //     } else {
    //         if (!root)
    //             return;
    //         else {
    //             cout << root->data << " ";
    //             topView(root->right);
    //         }
    //     }
    // }

    // // try2
    // void topView(Node * root) {
    //     leftView(root->left);
    //     cout << root->data << " ";
    //     rightView(root->right);
    // }

    // void leftView(Node * root) {
    //     if (!root)
    //         return;
    //     else {
    //         leftView(root->left);
    //         cout << root->data << " ";
    //     }
    // }

    // void rightView(Node * root) {
    //     if (!root)
    //         return;
    //     else {
    //         cout << root->data << " ";
    //         rightView(root->right);
    //     }
    // }

    void topView(Node * root) {
        queue<pair<int, Node *>> data;
        data.push(make_pair(0, root));
        map<int, Node *> result; // Node* array
        for(auto i = data.front(); !data.empty(); data.pop(), i = data.front()) {
            if (!i.second) // i.second == NULL
                continue;
            result.insert(i);
            data.push(make_pair(i.first + 1, i.second->right)); // index of array, right of node
            data.push(make_pair(i.first - 1, i.second->left)); // index of array (minus), left of node
        }
        for(auto i : result)
            cout << i.second->data << " "; // data of individual node
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

	myTree.topView(root);
    return 0;
}
