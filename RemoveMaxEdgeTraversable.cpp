// 1579. Remove Max Number Of Edges To Keep Graph Fully Traversable
class UnionFind{
public:
    vector<int> rank, parent;

    UnionFind(int n){
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u){
        if(u != parent[u]){
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool unionSets(int u, int v){
        int pu = find(u), pv = find(v);
        if(pu == pv){
            return false;
        }
        if (rank[pu] > rank[pv]){
            parent[pv] = pu;
        }
        else if (rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind ufA(n + 1), ufB(n + 1);
        int usedEdges = 0;
        for(const auto& edge:edges){
            if(edge[0] == 3){
                if(ufA.unionSets(edge[1], edge[2])){
                    ufB.unionSets(edge[1], edge[2]);
                    usedEdges++;
                }
            }
        }
        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (ufA.unionSets(edge[1], edge[2])) {
                    usedEdges++;
                }
            }
        }
        for (const auto& edge : edges) {
            if (edge[0] == 2) {
                if (ufB.unionSets(edge[1], edge[2])) {
                    usedEdges++;
                }
            }
        }
        
        if (isConnected(ufA, n) && isConnected(ufB, n)) {
            return edges.size() - usedEdges;
        } else {
            return -1;
        }
    }
    
private:
    bool isConnected(UnionFind& uf, int n) {
        int rootCount = 0;
        for (int i = 1; i <= n; ++i) {
            if (uf.find(i) == i) {
                rootCount++;
            }
        }
        return rootCount == 1;
    }
};
