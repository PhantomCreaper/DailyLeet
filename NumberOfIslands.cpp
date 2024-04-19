// 200. Number Of Islands
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()){
            return 0;
        }
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i = 0; i < rows; i++){
            for(int j=0; j < cols; j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid, i, j);            
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();

        if (r < 0 || c < 0 || r >= nr || c >= nc || grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '0';

        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }

};
