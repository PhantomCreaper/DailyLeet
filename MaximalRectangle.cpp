// 85. Maximal Rectangle
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        int max_area = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> height(cols + 1, 0);

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (matrix[row][col] == '1') {
                    height[col]++;
                } else {
                    height[col] = 0;
                }
            }
        
            stack<int> stk;
            for (int i = 0; i <= cols; ++i) {
                while (!stk.empty() && height[i] < height[stk.top()]) {
                    int h = height[stk.top()];
                    stk.pop();
                    int w = stk.empty() ? i : i - stk.top() - 1;
                    max_area = max(max_area, h * w);
                }
                stk.push(i);
            }
        }
        return max_area;
    }
};
