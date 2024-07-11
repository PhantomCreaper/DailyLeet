// 1190. Reverse Substring in Parantheses
class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stk;

        for (char c : s) {
            if (c == ')') {
                string temp;
                while (stk.top() != '(') {
                    temp += stk.top();
                    stk.pop();
                }
                stk.pop();
                for (char t : temp) {
                    stk.push(t);
                }
            } else {
                stk.push(c);
            }
        }

        string result;
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }

        return result;
    }
};
