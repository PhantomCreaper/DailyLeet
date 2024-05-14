// 1219. Path With Max gold
class Solution {
private:
    int dfs(int row, int col, vector<vector<int>>& grid){
        if(row<0 || row>=grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0){
            return 0;
        }
        int original = grid[row][col];
        grid[row][col] = 0;
        int maxGold = 0;

        maxGold = max(maxGold, dfs(row+1, col, grid));
        maxGold = max(maxGold, dfs(row-1, col, grid));
        maxGold = max(maxGold, dfs(row, col+1, grid));
        maxGold = max(maxGold, dfs(row, col-1, grid));

        grid[row][col] = original;
        return maxGold + original;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] > 0){
                    maxGold = max(maxGold, dfs(i, j, grid));
                }
            }
        }
        return maxGold;
    }
};
