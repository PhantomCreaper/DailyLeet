class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) return "0";

        stack<char> st;

        for (char digit : num) {
            while (!st.empty() && st.top() > digit && k > 0) {
                st.pop();
                k--;
            }
            if (!st.empty() || digit != '0') {
                st.push(digit);
            }
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        if (st.empty()) return "0";

        string result(st.size(), '0');
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};
