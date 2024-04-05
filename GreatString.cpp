//1544. Make the string great
class Solution {
public:
    string makeGood(string s) {
        int i = 0;
        stack<char> stack;
        for(char& c:s){
            if(!stack.empty() && abs(stack.top()-c) == 32){
                stack.pop();
            }
            else
                stack.push(c);
        }
        string result = "";
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        return result;
        }
};
