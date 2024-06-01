// 3110. Score of a String
class Solution {
public:
    int scoreOfString(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int score = 0;
        for(int i = 1; i < s.size(); i++){
            int j = i-1;
            score += abs(s[i]-s[j]);
        }

        return score;
    }
};
