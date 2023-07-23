// problem source: https://leetcode.com/problems/simplify-path/
// discussion reference: https://leetcode.com/problems/simplify-path/solutions/1847357/c-easy-stack-simple-explained-algorithm/
/*
다양한 형태의 Unix File Path(Absolute Path)가 들어오면, 유일한 형태(Canonical Path)로 단순화해서 출력
Canonical Path: 어떤 파일의 경로를 나타내기 위한 유일한 심볼
// -> /
~/ -> ~
/./ -> /
/../ -> /
/를 기준으로 넣다가 특수 상황일 때 예외 처리
*/
// solution
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stack;
        string result;
        for (int i = 0; i < path.length(); i++) {
            if (path[i] == '/')
                continue;
            string check;
            while (i < path.length() && path[i] != '/') {
                check += path[i];
                i++;
            }
            if (check == ".")
                continue;
            else if (check == "..") {
                if (!stack.empty())
                    stack.pop();
            } else
                stack.push(check);
        }
        while (!stack.empty()) {
            result = "/" + stack.top() + result;
            stack.pop();
        }
        if (result.length() == 0)
            return "/";
        return result;
    }
};
// outline
class Solution {
public:
    string simplifyPath(string path) {
        string result;
        int path_length = path.length();
        if (path[0] == '/') result += path[0];
        else cout << "not start with '/'" << endl;
        for (int cursor = 1; cursor < path_length; cursor++) {
            string check;            
            for (int i = 0; ; i++) {
                if (path[i] == '/') break;
                else check += path[i];
            }
            cout << check << endl;
            if (check == ".") { // case '/./'
                cout << "current" << endl;
            } else if (check == "..") { // case '/../'
                cout << "up" << endl;
            } else if (check == "") { // case '//'
                cout << "double to single" << endl;
            }
        }
        return result;
    }
};