// 834. Sum Distance of Trees
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto& edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> count(n, 1);
        vector<int> answer(n, 0);
        vector<bool> visited(n, false);

        function<void(int)> dfsCount = [&](int node){
            visited[node] = true;
            for(int neighbor:graph[node]){
                if(!visited[neighbor]){
                    dfsCount(neighbor);
                    count[node] += count[neighbor];
                    answer[0] += answer[neighbor] + count[neighbor];
                }
            }
        };

        function<void(int, int)> dfsAnswer = [&](int node, int parent){
            for(int neighbor:graph[node]){
                if(neighbor!=parent){
                    answer[neighbor] = answer[node] + (n - 2*count[neighbor]);
                    dfsAnswer(neighbor, node);
                }
            }
        };

        dfsCount(0);
        visited = vector<bool>(n, false);
        dfsAnswer(0, -1);

        return answer;
    }
};
