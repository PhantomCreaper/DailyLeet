// 1404. Number of Steps to Reduce Binary Number to One
class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        while (s != "1") {
            if (s.back() == '0') {
                s.pop_back();
            } else {
                int i = s.length() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if (i >= 0) {
                    s[i] = '1';
                } else {
                    s.insert(s.begin(), '1');
                }
            }
            steps++;
        }
        return steps;
    }
};
