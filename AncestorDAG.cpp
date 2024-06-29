// 2192. All Ancestors of Node in DAG
class Solution {
public:
    void getAncestorsDFS(int node, int ans, vector<vector<int>> &adj, vector<vector<int>> &result, vector<int> &visited) {
        visited[node] = 1;
        for(auto neighbour: adj[node]) {
            if(!visited[neighbour]) {
                getAncestorsDFS(neighbour, ans, adj, result, visited);
            }
        }

        if(node != ans) {
            result[node].push_back(ans);
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<vector<int>> result(n);

        for(auto i: edges) {
            adj[i[0]].push_back(i[1]);
        }

        for(int i=0; i<n; i++) {
            vector<int> visited(n);
            getAncestorsDFS(i, i, adj, result, visited);
        }

        return result;
    }
};
