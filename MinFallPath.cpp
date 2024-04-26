// 1289. Minimum Falling Path II
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1){
            return grid[0][0];
        }
        vector<vector<int>> dp = grid;
        for(int i = 1; i < n; i++){
            vector<int> mins = findTwoSmallest(dp[i-1]);
            for(int j = 0; j<n; j++){
                dp[i][j] = grid[i][j] + (mins[0] == dp[i-1][j] ? mins[1] : mins[0]);
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }

    vector<int> findTwoSmallest(vector<int>& row){
        int min1 = INT_MAX;
        int min2 = min1;
        for(int value:row){
            if(value<min1){
                min2 = min1;
                min1 = value;
            }
            else if(value<min2){
                min2 = value;
            }   
        }
        return{min1, min2};
    }
};
