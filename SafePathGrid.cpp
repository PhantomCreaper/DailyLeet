// 2812. Find safest path in grid
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        auto canReachWithSafeness = [&](int safeness) {
            if (dist[0][0] < safeness) return false;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            queue<pair<int, int>> q;
            q.push({0, 0});
            visited[0][0] = true;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                if (x == n - 1 && y == n - 1) return true;
                for (auto& dir : directions) {
                    int nx = x + dir.first;
                    int ny = y + dir.second;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && dist[nx][ny] >= safeness) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            return false;
        };
        
        int left = 0, right = n + n, result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canReachWithSafeness(mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};
