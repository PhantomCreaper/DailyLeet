// 1992. Find all groups of farmlands.
class Solution {
private:
    int numRows, numCols;

    void dfs(vector<vector<int>>& land, int r, int c, vector<int>& bounds) {
        if (r < 0 || r >= numRows || c < 0 || c >= numCols || land[r][c] != 1) {
            return;
        }
        
        land[r][c] = 0;

        // Update boundaries
        bounds[0] = min(bounds[0], r);
        bounds[1] = min(bounds[1], c);
        bounds[2] = max(bounds[2], r);
        bounds[3] = max(bounds[3], c);

        // Explore four directions
        dfs(land, r-1, c, bounds);
        dfs(land, r+1, c, bounds);
        dfs(land, r, c-1, bounds);
        dfs(land, r, c+1, bounds);
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        numRows = land.size();
        numCols = land[0].size();
        vector<vector<int>> result;

        for (int r = 0; r < numRows; ++r) {
            for (int c = 0; c < numCols; ++c) {
                if (land[r][c] == 1) {
                    vector<int> bounds = {r, c, r, c};
                    dfs(land, r, c, bounds);
                    result.push_back({bounds[0], bounds[1], bounds[2], bounds[3]});
                }
            }
        }

        return result;
    }
};
