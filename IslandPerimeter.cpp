// 463. Island Perimeter
class Solution {
public:
    int rows, cols;
    vector<vector<int>> visited;

    int islandPerimeter(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        visited.resize(rows, vector<int>(cols, 0));

        for(int i = 0; i < rows; i++){
            for( int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    return dfs(grid, i, j);
                }
            }
        }
        return 0;
    }

    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i>= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0){
            return 1;
        }
        if(visited[i][j]){
            return 0;
        }
        visited[i][j] = 1;

        int perimeter = 0;
        perimeter += dfs(grid, i-1, j);
        perimeter += dfs(grid, i+1, j);
        perimeter += dfs(grid, i, j+1);
        perimeter += dfs(grid, i, j-1);
        return perimeter;
    }
};
