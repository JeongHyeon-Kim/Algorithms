// problem source: https://www.hackerrank.com/challenges/30-linked-list-deletion/problem
// discussion reference: https://www.hackerrank.com/challenges/30-linked-list-deletion/forum/comments/177867
#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public:

          Node* removeDuplicates(Node *head)
          {
            //Write your code here
            /*
            // How can make this code work?
            Node* newNode = new Node(head->data);
            while (head != NULL) {
                Node *copyNode = new Node(head->data);
                if (head->next == NULL) { // Last Node
                    head->next = copyNode;
                } else if (head->data != head->next->data) {
                    Node *start = newNode;
                    while(start->next != NULL) {
                        start = start->next;
                    }
                    cout << copyNode->data << endl;
                    start->next = copyNode;
                }
                head = head->next;
            }
            return newNode;
            */
            if(head == NULL)
                return NULL;
            Node *s = head;
            while(s->next != NULL){
                if(s->data == s->next->data)
                    s->next = s->next->next; // skipping node
                else
                    s = s->next; // moving node
            }
            return head;
          }

          Node* insert(Node *head,int data)
          {
               Node* p=new Node(data);
               if(head==NULL){
                   head=p;

               }
               else if(head->next==NULL){
                   head->next=p;

               }
               else{
                   Node *start=head;
                   while(start->next!=NULL){
                       start=start->next;
                   }
                   start->next=p;

               }
                    return head;


          }
          void display(Node *head)
          {
                  Node *start=head;
                    while(start)
                    {
                        cout<<start->data<<" ";
                        start=start->next;
                    }
           }
};

int main()
{
	Node* head=NULL;
  	Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }
    head=mylist.removeDuplicates(head);

	mylist.display(head);

}
