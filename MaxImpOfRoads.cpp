// 2285. Maximum Importance Of Roads
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        
        for (const auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return degree[a] > degree[b];
        });
        
        vector<int> value(n);
        for (int i = 0; i < n; ++i) {
            value[indices[i]] = n - i;
        }
        
        long long totalImportance = 0;
        for (const auto& road : roads) {
            totalImportance += value[road[0]] + value[road[1]];
        }
        
        return totalImportance;
    }
};
