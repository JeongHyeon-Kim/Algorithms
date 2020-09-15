// problem source: https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem
// discussion reference: https://www.hackerrank.com/varUndefined
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int test_case;
    cin >> test_case;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    map<string,int> phone_book;
    for (int i = 0; i < test_case; i++){
        string name;
        int phone_number;
        cin >> name >> phone_number;
        phone_book[name] = phone_number;
    }
    string input_name;
    while (cin >> input_name) {
        if (phone_book.find(input_name) != phone_book.end())
            cout << input_name << "=" << phone_book.find(input_name)->second << endl;
        else
            cout << "Not found" << endl;
    }

    // Terminated due to timeout
    // do {
    //     string input_name;
    //     cin >> input_name;
    //     bool find = false;
    //     map<string, int>::iterator it;
    //     for (it = phone_book.begin(); it != phone_book.end(); it++) {
    //         if (input_name == it->first) {
    //             cout << it->first << "=" << it->second << endl;
    //             find = true;
    //             break;
    //         }
    //     }
    //     if (!find)
    //         cout << "Not found" << endl;
    // } while (cin.peek() == '\n');

    return 0;
}
