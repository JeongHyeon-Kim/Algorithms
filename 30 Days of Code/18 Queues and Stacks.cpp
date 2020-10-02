// problem source: https://www.hackerrank.com/challenges/30-queues-stacks/problem
// discussion reference: https://velog.io/@choiiis/C-STL-stack-클래스-정리, https://twpower.github.io/76-how-to-use-queue-in-cpp
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    //Write your code here
    protected:
        stack<char> stack_impl;
        queue<char> queue_impl;

    public:
        void pushCharacter(char ch) {
            stack_impl.push(ch);
        }
        void enqueueCharacter(char ch) {
            queue_impl.push(ch);
        }
        char popCharacter() {
            return stack_impl.top();
        }
        char dequeueCharacter() {
            return queue_impl.front();
        }
};

int main() {
    // read the string s.
    string s;
    getline(cin, s);

  	// create the Solution class object p.
    Solution obj;

    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }

    bool isPalindrome = true;

    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;

            break;
        }
    }

    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }

    return 0;
}
