// 623. Add One Row To Tree

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val, root, nullptr);
            return newRoot;
        }
        queue<TreeNode*> q;
        q.push(root);
        int curr = 1;
        while (!q.empty()) {
            if (curr == depth - 1) {
                size_t size = q.size();
                for (size_t i = 0; i < size; ++i) {
                    TreeNode* node = q.front();
                    q.pop();
                    
                    TreeNode* newLeft = new TreeNode(val);
                    TreeNode* newRight = new TreeNode(val);
                    
                    newLeft->left = node->left;
                    newRight->right = node->right;
                    
                    node->left = newLeft;
                    node->right = newRight;
                }
                break;
            }
            
            size_t size = q.size();
            for (size_t i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            curr++;
        }
        return root;
    }
};
