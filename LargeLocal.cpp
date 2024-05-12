// 2373. Largest local values in a matrix
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n-2, vector<int>(n-2));
        for(int i = 0; i<=n-3; i++){
            for(int j = 0; j<=n-3; j++){
                int maxVal = 0;

                for(int di = 0; di<3; di++){
                    for(int dj = 0; dj<3; dj++){
                        maxVal = max(maxVal, grid[i+di][j+dj]);
                    }
                }
                maxLocal[i][j] = maxVal;
            }
        }
        return maxLocal;
    }
};
