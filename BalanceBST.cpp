// 1382. Balance BST
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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> values;
        inOrderTraversal(root, values);
        
        return constructBalancedBST(values, 0, values.size() - 1);
    }
    
private:
    void inOrderTraversal(TreeNode* node, vector<int>& values) {
        if (node == nullptr) return;
        inOrderTraversal(node->left, values);
        values.push_back(node->val);
        inOrderTraversal(node->right, values);
    }
    
    TreeNode* constructBalancedBST(const vector<int>& values, int start, int end) {
        if (start > end) return nullptr;
        
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(values[mid]);
        node->left = constructBalancedBST(values, start, mid - 1);
        node->right = constructBalancedBST(values, mid + 1, end);
        
        return node;
    }
};
