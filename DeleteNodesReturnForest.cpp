// 1110. Delete Nodes And Return Forest
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;
        
        root = dfs(root, toDeleteSet, forest);
        
        if (root != nullptr) {
            forest.push_back(root);
        }
        
        return forest;
    }
    
    TreeNode* dfs(TreeNode* node, unordered_set<int>& toDeleteSet, vector<TreeNode*>& forest) {
        if (node == nullptr) return nullptr;
        
        node->left = dfs(node->left, toDeleteSet, forest);
        node->right = dfs(node->right, toDeleteSet, forest);
        
        if (toDeleteSet.count(node->val)) {
            if (node->left != nullptr) {
                forest.push_back(node->left);
            }
            if (node->right != nullptr) {
                forest.push_back(node->right);
            }
            return nullptr;
        }
        
        return node;
    }
};
