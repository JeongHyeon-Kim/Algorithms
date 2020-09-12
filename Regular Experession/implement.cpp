#include <iostream>
#include <string>
#include <regex>

using namespace std;

string implement(string new_id) {
	string edited_id;
    // Remove extra characters other than lowercase letters, numbers, -(minus), _(underscore), .(full stop)
    regex reg("[^(a-z0-9-_.)]");
    edited_id = regex_replace(new_id, reg, "");
    //cout << new_id << endl;
    return edited_id;
}

int main() {
	// your code goes here
	string input_id, edited_id;
	cin >> input_id;
	edited_id = implement(input_id);
	cout << edited_id << endl;
	return 0;
}
