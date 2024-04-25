// 2370. Longest ideal subsequence
class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);

        for(char c:s){
            int maxLen = 0;
            int index = c - 'a';

            for(int j = max(0, index-k); j<=min(25, index+k); j++){
                maxLen = max(maxLen, dp[j]);
            }

            dp[index] = maxLen + 1;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
