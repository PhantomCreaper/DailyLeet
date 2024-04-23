// 310. Minimum Height Trees
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        vector<set<int>> graph(n);
        for(const auto& edge:edges){
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        
        queue<int> leaves;
        for(int i =0; i<n; i++){
            if(graph[i].size()==1){
                leaves.push(i);
            }
        }

        int rem = n;
        while(rem>2){
            int leavesCount = leaves.size();
            rem -= leavesCount;
            for(int i = 0; i < leavesCount; i++){
                int leaf = leaves.front();
                leaves.pop();
                int neighbor = *graph[leaf].begin();
                graph[neighbor].erase(leaf);
                if(graph[neighbor].size() == 1){
                    leaves.push(neighbor);
                }
            }
        }

        vector<int> results;
        while(!leaves.empty()){
            results.push_back(leaves.front());
            leaves.pop();
        }

        return results;
    }

};
