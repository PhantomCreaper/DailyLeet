// 1530. Number of Good Leaf Node Pairs
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int result = 0;
        dfs(root, distance, result);
        return result;
    }

private:
    vector<int> dfs(TreeNode* node, int distance, int& result) {
        if (!node) return {};
        if (!node->left && !node->right) return {1};

        vector<int> leftDistances = dfs(node->left, distance, result);
        vector<int> rightDistances = dfs(node->right, distance, result);

        for (int lDist : leftDistances) {
            for (int rDist : rightDistances) {
                if (lDist + rDist <= distance) {
                    result++;
                }
            }
        }

        vector<int> currentDistances;
        for (int lDist : leftDistances) {
            if (lDist + 1 <= distance) {
                currentDistances.push_back(lDist + 1);
            }
        }
        for (int rDist : rightDistances) {
            if (rDist + 1 <= distance) {
                currentDistances.push_back(rDist + 1);
            }
        }

        return currentDistances;
    }
};
