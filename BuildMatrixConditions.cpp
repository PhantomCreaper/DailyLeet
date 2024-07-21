// 2392. Build Matrix With Conditions
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> result(k, vector<int>(k, 0));
        
        auto topologicalSort = [](int k, vector<vector<int>>& conditions) {
            vector<vector<int>> adj(k + 1);
            vector<int> inDegree(k + 1, 0);
            
            for (auto& cond : conditions) {
                adj[cond[0]].push_back(cond[1]);
                inDegree[cond[1]]++;
            }
            
            queue<int> q;
            for (int i = 1; i <= k; ++i) {
                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }
            
            vector<int> topoOrder;
            while (!q.empty()) {
                int node = q.front(); q.pop();
                topoOrder.push_back(node);
                
                for (int neighbor : adj[node]) {
                    if (--inDegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
            
            if (topoOrder.size() != k) {
                return vector<int>();
            }
            return topoOrder;
        };
        
        vector<int> rowOrder = topologicalSort(k, rowConditions);
        vector<int> colOrder = topologicalSort(k, colConditions);
        
        if (rowOrder.empty() || colOrder.empty()) {
            return {};
        }
        
        unordered_map<int, int> rowPos, colPos;
        for (int i = 0; i < k; ++i) {
            rowPos[rowOrder[i]] = i;
            colPos[colOrder[i]] = i;
        }
        
        for (int i = 1; i <= k; ++i) {
            result[rowPos[i]][colPos[i]] = i;
        }
        
        return result;
    }
};
