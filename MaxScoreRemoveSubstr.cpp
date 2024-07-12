// 1717. Maximum Score From Removing Substring
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            swap(x, y);
            reverse(s.begin(), s.end());
        }
        
        int totalScore = 0;
        stack<char> stk;
        
        for (char ch : s) {
            if (!stk.empty() && stk.top() == 'a' && ch == 'b') {
                stk.pop();
                totalScore += x;
            } else {
                stk.push(ch);
            }
        }
        
        string remaining;
        while (!stk.empty()) {
            remaining.push_back(stk.top());
            stk.pop();
        }
        reverse(remaining.begin(), remaining.end());
        
        for (char ch : remaining) {
            if (!stk.empty() && stk.top() == 'b' && ch == 'a') {
                stk.pop();
                totalScore += y;
            } else {
                stk.push(ch);
            }
        }
        
        return totalScore;
    }
};
