// 504. Freedom Trail
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        vector<vector<int>> dp(m+1, vector<int>(n, INT_MAX));
        unordered_map<char, vector<int>> charPositions;

        for(int i = 0; i < n; i++){
            charPositions[ring[i]].push_back(i);
        }

        for(int pos:charPositions[key[0]]){
            dp[1][pos] = min(pos, n - pos) + 1;
        }

        for(int i = 1; i < m; i++){
            for(int j:charPositions[key[i]]){
                for(int k:charPositions[key[i-1]]){
                    int dist = abs(j-k);
                    int step = min(dist, n - dist) + 1;
                    dp[i+1][j] = min(dp[1+i][j], dp[i][k]+step);
                }
            }
        }

        int minSteps = INT_MAX;
        for(int pos:charPositions[key[m-1]]){
            minSteps = min(minSteps, dp[m][pos]);
        }

        return minSteps;
    }
};
